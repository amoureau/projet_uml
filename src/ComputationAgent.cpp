//---------- Réalisation de la classe <ComputationAgent> (fichier ComputationAgent.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ComputationAgent.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ComputationAgent::loadData(void)
{
    loadSensor();
    loadPrivateIndividual();
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




    // stockage de base
    hmapIdSensor.clear();
    hmapIdPrivateIndividual.clear();

    // lien - structure de données annexe
    mapCoordSensor.clear(); 
    hmapIdSensorPrivateIndividual.clear(); 

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