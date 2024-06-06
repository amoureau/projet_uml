//---------- Réalisation de la classe <ComputationAgent> (fichier ComputationAgent.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ComputationAgent.h"
#include "Timestamp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC



// setter getter +




//----------------------------------------------------- Méthodes publiques
void ComputationAgent::loadData(void)
{
    loadSensor();
    loadPrivateIndividual();
    loadAttributes();
    loadMesurements();
    loadCleaner();
    loadProvider();
    
}

int ComputationAgent::ComputeMeanQuality(double latitude, double longitude, double radius, Timestamp startTime, Timestamp endTime)
{
    if (radius <= 0) {
        throw invalid_argument("Le rayon doit être positif!");
    }

    if ((latitude > 90) || (latitude < -90)) {
        throw invalid_argument("La latitude doit être comprise entre -90° et 90°");
    }

    if ((longitude > 180) || (longitude < -180)) {
        throw invalid_argument("La longitude doit être comprise entre -180° et 180°");
    }

    if (startTime > endTime) {
        throw invalid_argument("La date de fin doit être > à la date du début");     
    }

    vector<string> listeAttributs = {"O3", "NO2", "PM10", "SO2"};

    vector<int> listeMoyennes;
    int indiceAtmo = -1;

    for (string attribut : listeAttributs) {
        double moyenne = ComputeMeanForAnAttribute(latitude, longitude, attribut, radius, startTime, endTime);
        
        if (moyenne != -1) {
            listeMoyennes.push_back(moyenne);
            int indice = indiceCorrespondingToMean(attribut, moyenne);
            //cout << "Indice pour " << attribut << " : " << indice << endl;
            if (indice > indiceAtmo) {
                indiceAtmo = indice;
            }
        } else {
            throw invalid_argument("Il n’y a pas de mesure pour au moins une des molécules donc calcul de ATMO impossible!");
        }
    }

    return indiceAtmo;
}


bool ComputationAgent::ComputeSensorAnalysed(int sensorId, double areaRadius) {
    Sensor *sensor = hmapIdSensor[sensorId];

    bool anomalies = false;
    unordered_map<string, int> dicoNbValueCapteur, dicoNbValueAll, dicoNbVoisin;
    unordered_map<string, double> dicoMeanCapteur, dicoMeanAll, dicoSumOfSquaresAll, dicoSdAll;
    dicoMeanCapteur["O3"] = dicoMeanCapteur["NO2"] = dicoMeanCapteur["SO2"] = dicoMeanCapteur["PM10"] = 0;
    string list_molec[] = { "O3", "NO2", "SO2", "PM10"};

    for (string &molecule : list_molec) {
        int meanForAttribute = ComputeMeanForAnAttribute(sensor->getLatitude(), sensor->getLongitude(), molecule, areaRadius, 0, 0);
        dicoMeanAll[molecule] = (meanForAttribute == -1 ? 0 : meanForAttribute);
    }

    double latSensor = hmapIdSensor[ sensorId ]->getLatitude();
    double lngSensor = hmapIdSensor[ sensorId ]->getLongitude();
    for (Measurement *me: vecteurMeasurements) {
        string attributeDescription = me->getAttribute()->getId();
        if (me->getSensor()->getId() == sensorId) {
            dicoMeanCapteur[ attributeDescription ] += me->getValue();
            dicoNbValueCapteur[ attributeDescription ] += 1;
        } else {
            Sensor *s = me->getSensor();
            double distance = calculateDistance(latSensor, lngSensor, s->getLatitude(), s->getLongitude());
            if (distance <= areaRadius) {
                dicoNbVoisin[ me->getAttribute()->getId() ] += 1;
            }
        }

        dicoSumOfSquaresAll[ attributeDescription ] += ( me->getValue() - dicoMeanAll[ attributeDescription ])*( me->getValue() - dicoMeanAll[ attributeDescription ]);
        dicoNbValueAll[ attributeDescription ] += 1;
    }


    //On exclut les données du capteur s'il y a un problème pour la moyenne d'une des molécules au moins
    for (string &molecule : list_molec) {
        if (dicoNbValueAll[molecule] == 0) continue;
        if (dicoNbValueCapteur[molecule] == 0) continue;

        if (dicoNbVoisin [molecule] == 0) {
            throw invalid_argument("Analyse impossible car il y a aucun autre capteur a de mesure sur la même molécule!");
        }

        dicoMeanCapteur[ molecule ] = dicoMeanCapteur[ molecule ] / (double) dicoNbValueCapteur[ molecule ];
        dicoSdAll[ molecule ] = sqrt( dicoSumOfSquaresAll[molecule] / (double) dicoNbValueAll[molecule] );

        //cout << "Nom |" << " Capteur |" << " All |" << " Ecart-Type All " << endl;
        //cout << molecule << "    " << dicoMeanCapteur[ molecule ] << "        " << dicoMeanAll[molecule] << "         " << dicoSdAll[molecule] << endl;  

        if ((dicoMeanCapteur[ molecule ] > dicoMeanAll[molecule] + dicoSdAll[molecule] ) 
            || (dicoMeanCapteur[ molecule ] < dicoMeanAll[molecule] - dicoSdAll[molecule])) {
                anomalies = true;
        }
    }

    return anomalies;
}



double ComputationAgent::ComputeMeanForAnAttribute ( double latitude, double longitude, string attribute, double radius, Timestamp startTime, Timestamp endTime) {
    
    if (radius <= 0) {
        throw invalid_argument("Le rayon doit être positif!");
    }

    if ((latitude > 90) || (latitude < -90)) {
        throw invalid_argument("La latitude doit être comprise entre -90° et 90°");
    }

    if ((longitude > 180) || (longitude < -180)) {
        throw invalid_argument("La longitude doit être comprise entre -180° et 180°");
    }

    if (startTime > endTime) {
        throw invalid_argument("La date de fin doit être > à la date du début");     
    }

    if ( hmapAttributes.count(attribute) == 0 ) {
        throw invalid_argument("La molécule n'existe pas!");     
    }
    
    double somme = 0;
    double nbCapteurs = 0;
    Attributes attributes = *(hmapAttributes[attribute]);

    for (Measurement *me : vecteurMeasurements) {
        Timestamp mesureTime = me->getDate();
        Sensor *sensor = me->getSensor();

        if ( me->getAttribute()->getId() == attributes.getId() ) {
            double distance = calculateDistance(latitude, longitude, sensor->getLatitude(), sensor->getLongitude());
            if ((( startTime <= mesureTime  && mesureTime <= endTime) || (startTime == 0 && endTime == 0)) && (distance <= radius))
            {
                // cout << startTime << " " << mesureTime << " " << endTime << endl;
                somme += me->getValue();
                nbCapteurs++;
            }
        }
    }

    if (nbCapteurs == 0) 
        return -1;
    else
        return somme/nbCapteurs;
}

int ComputationAgent::indiceCorrespondingToMean(string attribut, double moyenne)
{
    if (attribut == "O3") {
        if (moyenne <= 29) {
            return 1;
        }
        else if (moyenne <= 54) {
            return 2;
        }
        else if (moyenne <= 79) {
            return 3;
        }
        else if (moyenne <= 104) {
            return 4;
        }
        else if (moyenne <= 129) {
            return 5;
        }
        else if (moyenne <= 149) {
            return 6;
        }
        else if (moyenne <= 179) {
            return 7;
        }
        else if (moyenne <= 209) {
            return 8;
        }
        else if (moyenne <= 239) {
            return 9;
        }
        else {
            return 10;
        }
    }
    else if (attribut == "NO2") {
        if (moyenne <= 29) {
            return 1;
        }
        else if (moyenne <= 54) {
            return 2;
        }
        else if (moyenne <= 84) {
            return 3;
        }
        else if (moyenne <= 109) {
            return 4;
        }
        else if (moyenne <= 134) {
            return 5;
        }
        else if (moyenne <= 164) {
            return 6;
        }
        else if (moyenne <= 199) {
            return 7;
        }
        else if (moyenne <= 274) {
            return 8;
        }
        else if (moyenne <= 399) {
            return 9;
        }
        else {
            return 10;
        }
    }
    else if (attribut == "PM10") {
        if (moyenne <= 6) {
            return 1;
        }
        else if (moyenne <= 13) {
            return 2;
        }
        else if (moyenne <= 20) {
            return 3;
        }
        else if (moyenne <= 27) {
            return 4;
        }
        else if (moyenne <= 34) {
            return 5;
        }
        else if (moyenne <= 41) {
            return 6;
        }
        else if (moyenne <= 49) {
            return 7;
        }
        else if (moyenne <= 64) {
            return 8;
        }
        else if (moyenne <= 79) {
            return 9;
        } else {
            return 10;
        }
    }
    else if (attribut == "SO2") {
        if (moyenne <= 39) {
            return 1;
        }
        else if (moyenne <= 79) {
            return 2;
        }
        else if (moyenne <= 119) {
            return 3;
        }
        else if (moyenne <= 159) {
            return 4;
        }
        else if (moyenne <= 199) {
            return 5;
        }
        else if (moyenne <= 249) {
            return 6;
        }
        else if (moyenne <= 299) {
            return 7;
        }
        else if (moyenne <= 399) {
            return 8;
        }
        else if (moyenne <= 499) {
            return 9;
        }
        else {
            return 10;
        }
    }
    else {
        return 0;
    }
}
//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

ComputationAgent::ComputationAgent ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <ComputationAgent>" << endl;
#endif

} //----- Fin de ComputationAgent défaut



ComputationAgent::~ComputationAgent ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <ComputationAgent>" << endl;
#endif

    // free memory
    for(auto sensor : hmapIdSensor)
    {
        delete sensor.second;
    }

    for(auto privateInd : hmapIdPrivateIndividual)
    {
        delete privateInd.second;
    }

    for(auto att : hmapAttributes)
    {
        delete att.second;
    }

    for(auto mes : vecteurMeasurements)
    {
        delete mes;
    }

    for(auto cleaner : hmapIdCleaner)
    {
        delete cleaner.second;
    }

    for(auto provider : hmapIdProvider)
    {
        delete provider.second;
    }




    // stockage de base
    hmapIdSensor.clear();
    hmapIdPrivateIndividual.clear();
    hmapAttributes.clear();
    vecteurMeasurements.clear();
    hmapIdCleaner.clear();
    hmapIdProvider.clear();


    // lien - structure de données annexe
    mapCoordSensor.clear(); 
    hmapIdSensorPrivateIndividual.clear(); 
    hmapDescriptionAttributes.clear();
    

} //----- Fin de ~ComputationAgent


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void ComputationAgent::loadSensor(void)
{

    // chemins acces fichiers:
    string fichierCSV = "dataset/sensors.csv";
    ifstream fichier(fichierCSV);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        

        int id;
        double latitude;
        double longitude;
        string valeur;

        // Lecture des valeurs séparées par des virgules
        getline(iss, valeur, ';');

        size_t pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());

        id = stoi(valeur);
        getline(iss, valeur, ';');
        latitude = stod(valeur);
        getline(iss, valeur, ';');
        longitude = stod(valeur);

        Sensor* sensor = new Sensor(id, latitude, longitude, nullptr);
        hmapIdSensor[id] = sensor;
        mapCoordSensor[make_pair(latitude, longitude)].push_back(sensor);
    }
}

void ComputationAgent::loadPrivateIndividual(void)
{
    // chemins acces fichiers:
    string fichierCSV = "dataset/users.csv";
    ifstream fichier(fichierCSV);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        

        int idPrivateIndividual;
        int idSensor;
        string valeur;

        // Lecture des valeurs séparées par des virgules

        getline(iss, valeur, ';');
        size_t pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        idPrivateIndividual = stoi(valeur);

        getline(iss, valeur, ';');
        pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        idSensor = stoi(valeur);

        Sensor *sensor = hmapIdSensor[idSensor];
        PrivateIndividual *privateIndividual = new PrivateIndividual(idPrivateIndividual);
        sensor->setPrivateIndividual(privateIndividual); // imprtatnt
        hmapIdPrivateIndividual[idPrivateIndividual] = privateIndividual;
        hmapIdSensorPrivateIndividual[idSensor] = privateIndividual;


    }

}

void ComputationAgent::loadAttributes(void)
    {
        // chemins acces fichiers:
        string fichierCSV = "dataset/attributes.csv";
        ifstream fichier(fichierCSV);
        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
            exit(1);
        }

        string ligne;
        getline(fichier, ligne); // skip first line
        while (getline(fichier, ligne)) {
            istringstream iss(ligne);
            

            string idAttribute;
            string unit;
            string description;

            string valeur;

            // Lecture des valeurs séparées par des points virgules
            getline(iss, valeur, ';');
            idAttribute = valeur;
            getline(iss, valeur, ';');
            unit = valeur;
            getline(iss, valeur, ';');
            description = valeur;

            Attributes *att = new Attributes(idAttribute, unit, description);
            hmapAttributes[idAttribute] = att;
            hmapDescriptionAttributes[description] = att;
        }
    }

void ComputationAgent::loadMesurements(void)
{
    // chemins acces fichiers:
    string fichierCSV = "dataset/measurements.csv";
    ifstream fichier(fichierCSV);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        

        
        string valeur;

        // Lecture des valeurs séparées par des points virgules
        getline(iss, valeur, ';');
        string dateString = valeur;
        Timestamp date(dateString);


        getline(iss, valeur, ';');
        size_t pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        int idSensor = stoi(valeur);

        getline(iss, valeur, ';');
        string idAttributes = valeur;


        getline(iss, valeur, ';');
        double value = stod(valeur);

        Sensor *sensor = hmapIdSensor[idSensor];
        Attributes *att = hmapAttributes[idAttributes];

        Measurement *mes = new Measurement(value, date, sensor, att);
        vecteurMeasurements.push_back(mes);
    }
}

void ComputationAgent::loadCleaner(void)
{
    // chemins acces fichiers:
    string fichierCSV = "dataset/cleaners.csv";
    ifstream fichier(fichierCSV);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        

        int idCleaner;
        double latitude;
        double longitude;
        Timestamp dateStart;
        Timestamp dateEnd;

        string valeur;

        // Lecture des valeurs séparées par des virgules

        getline(iss, valeur, ';');
        size_t pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        idCleaner = stoi(valeur);

        getline(iss, valeur, ';');
        latitude = stod(valeur);

        getline(iss, valeur, ';');
        longitude = stod(valeur);

        getline(iss, valeur, ';');
        dateStart = Timestamp(valeur);

        getline(iss, valeur, ';');
        dateEnd = Timestamp(valeur);

        Cleaner *cleaner = new Cleaner(idCleaner, latitude, longitude, dateStart, dateEnd, nullptr);
        this->hmapIdCleaner[idCleaner] = cleaner;
    }
}

void ComputationAgent::loadProvider(void)
{
    // chemins acces fichiers:
    string fichierCSV = "dataset/providers.csv";
    ifstream fichier(fichierCSV);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);

        int idProvider;
        int idCleaner;

        string valeur;
        
        // Lecture des valeurs séparées par des points virgules
        getline(iss, valeur, ';');
        size_t pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        idProvider = stoi(valeur);

        getline(iss, valeur, ';');
        pos = valeur.find_first_of("0123456789");
        valeur = valeur.substr(pos, valeur.size());
        idCleaner = stoi(valeur);

        Cleaner *cleaner = hmapIdCleaner.at(idCleaner);
        Provider *provider = new Provider(idProvider);
        cleaner->setProvider(provider);
        hmapIdProvider[idProvider] = provider;

    }
}