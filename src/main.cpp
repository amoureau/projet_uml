#include "Results.h"

#include "User.h"
#include "Admin.h"
#include "Sensor.h"
#include "ComputationAgent.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// Définition d'un objet "Personne" avec des attributs nom, prénom et âge

static void loadSensor(unordered_map<int, Sensor> &sensors, map<pair<double, double>, vector<Sensor>> &sensors2)
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

        Sensor sensor(id, latitude, longitude);
        
        sensors[id] = sensor;
        sensors2[make_pair(latitude, longitude)].push_back(sensor);
    }
}





int main(void)
{
    unordered_map<int, Sensor> sensors;
    map<pair<double, double>, vector<Sensor>> sensors2;
    loadSensor(sensors, sensors2);

    int nbSensors = sensors.size();
    cout << "Liste des capteurs : " << endl;
    for (auto sensor : sensors) {
        cout << "id: " << sensor.first << " Sensor: " << sensor.second << endl;
    }
    cout << "Nombre de capteurs : " << nbSensors << endl;

    cout << "Liste des capteurs selon la lat et long: " << endl;
    for (auto sensor : sensors2) {
        cout << "lat: " << sensor.first.first << " long: " << sensor.first.second << " Sensors: ";
        for (auto s : sensor.second) {
            cout << s << " ";
        }
        cout << endl;
    }
    


    return 0;
}