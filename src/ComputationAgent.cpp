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

        Sensor sensor = Sensor(id, latitude, longitude);
        
        hmapIdSensor[id] = sensor;
        mapCoordSensor[make_pair(latitude, longitude)].push_back(sensor);
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

    hmapIdSensor.clear();
    mapCoordSensor.clear();

} //----- Fin de ~ComputationAgent


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

