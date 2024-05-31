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
/*
int ComputationAgent::ComputeMeanQuality(double latitude, double longitude, double radius, Timestamp startTime, Timestamp endTime)
{
    vector<string> listeAttributs = {"O3", "NO2", "PM10", "SO2"};
    vector<int> listeMoyennes = {0, 0, 0, 0};
    int indiceAtmo = 0;

}
*/

bool ComputationAgent::ComputeSensorAnalysed(int sensorId, double areaRadius) {
    Sensor *sensor = hmapIdSensor[sensorId];

    bool anomalies = false;
    unordered_map<string, int> dicoMeanCapteur, dicoMeanAll, dicoSumOfSquaresAll, dicoSdAll, dicoNbValueAll;
    dicoMeanCapteur["O3"] = dicoMeanCapteur["NO2"] = dicoMeanCapteur["SO2"] = dicoMeanCapteur["PM10"] = 0;
    string list_molec[] = { "O3", "NO2", "SO2", "PM10"};

    for (string &molecule : list_molec) {
        Attributes *attributes = hmapAttributes[molecule];
        dicoMeanAll[molecule] = ComputeMeanForAnAttribute(*attributes, sensor->getLatitude(), sensor->getLongitude(), areaRadius, 0, 0);
    }

    for (Measurement *me: vecteurMeasurements) {
        string attributeDescription = me->getAttribute()->getDescription();
        if (me->getSensor()->getId() == sensorId) {
            dicoMeanCapteur[ attributeDescription ] += me->getValue();
        }

        dicoSumOfSquaresAll[ attributeDescription ] += ( me->getValue() - dicoMeanAll[ attributeDescription ])*( me->getValue() - dicoMeanAll[ attributeDescription ]);
        dicoNbValueAll[ attributeDescription ] += 1;
    }

    //On exclue les données du capteur s'il y a un problème pour la moyenne d'une des molécules au moins
    for (string &molecule : list_molec) {
        dicoSdAll[ molecule ] = sqrt( (1/dicoNbValueAll[molecule]) * dicoSumOfSquaresAll[molecule] );
        if ((dicoMeanCapteur[ molecule ] > dicoMeanAll[molecule] + 3*dicoSdAll[molecule] ) 
            || (dicoMeanCapteur[ molecule ] < dicoMeanAll[molecule] - 3*dicoSdAll[molecule])) {
                anomalies = true;
        }
    }

    return true;
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

double ComputationAgent::ComputeMeanForAnAttribute ( Attributes &attribute, double latitude, double longitude, double radius, Timestamp startTime, Timestamp endTime) {
    double moyenne = 0;
    for (Measurement *me : vecteurMeasurements) {
        Timestamp mesureTime = me->getDate();
        Sensor *sensor = me->getSensor();

        if ( me->getAttribute()->getId() == attribute.getId() ) {
            if ((( startTime < mesureTime  && mesureTime < endTime) || (startTime == 0 && endTime == 0))
                && (calculateDistance(latitude, longitude, sensor->getLatitude(), sensor->getLongitude())))
            {
                moyenne += me->getValue();
            }
        }
    }
    return moyenne;
}

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

        Sensor* sensor = new Sensor(id, latitude, longitude);
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

        Sensor *sensor = hmapIdSensor[idSensor]; // ..?????p,sqfdsqf checker si c'est pas nul
        PrivateIndividual *privateIndividual = new PrivateIndividual(idPrivateIndividual, sensor);
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
        string description = valeur;


        getline(iss, valeur, ';');
        double value = stod(valeur);

        Sensor *sensor = hmapIdSensor[idSensor];
        Attributes *att = hmapDescriptionAttributes[description];
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

        Cleaner *cleaner = new Cleaner(idCleaner, latitude, longitude, dateStart, dateEnd);
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

        Cleaner *cleaner = this->hmapIdCleaner[idCleaner];
        Provider *provider = new Provider(idProvider, cleaner);
        hmapIdProvider[idProvider] = provider;

    }
}