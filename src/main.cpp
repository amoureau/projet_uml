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

using namespace std;

// Définition d'un objet "Personne" avec des attributs nom, prénom et âge

static unordered_map<int, Sensor>& loadSensor(unordered_map<int, Sensor> &sensors)
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
        valeur = valeur.substr(valeur.size()-1, valeur.size());
        id = stoi(valeur);
        getline(iss, valeur, ';');
        latitude = stod(valeur);
        getline(iss, valeur, ';');
        longitude = stod(valeur);

        Sensor sensor(id, latitude, longitude);
        
        sensors[id] = sensor;
    }

    return sensors;
}





int main(void)
{
    unordered_map<int, Sensor> sensors;
    sensors = loadSensor(sensors);

    
    cout << "Liste des capteurs : " << endl;
    for (auto sensor : sensors) {
        cout << sensor.second << endl;
    }
    


    return 0;
}