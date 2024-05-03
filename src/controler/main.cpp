#include "../view/Results.h"

#include "../model/User.h"
#include "../model/Admin.h"
#include "../model/Sensor.h"
#include "../model/ComputationAgent.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Définition d'un objet "Personne" avec des attributs nom, prénom et âge

static vector<Sensor>& loadSensor(void)
{
    vector<Sensor> sensors;

    // chemins acces fichiers:
    string fichierCSV = "../../dataset/sensors.csv";
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
        valeur = valeur.substr(0, valeur.size());
        id = stoi(valeur);
        getline(iss, valeur, ',');
        latitude = stod(valeur);
        getline(iss, valeur, ',');
        longitude = stod(valeur);

        Sensor sensor = Sensor(id, latitude, longitude);
        sensors.push_back(sensor);

    }

    return sensors;
}





int main(void)
{
    vector<Sensor> sensors = loadSensor();

    cout << "Liste des capteurs : " << endl;
    for (Sensor sensor : sensors) {
        cout << sensor.getId() << " : " << sensor.getLatitude() << " : " << sensor.getLongitude() << endl;
    }


    return 0;
}