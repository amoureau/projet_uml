#include "Results.h"

#include "User.h"
#include "Admin.h"
#include "Sensor.h"
#include "ComputationAgent.h"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;



int main(void)
{
    /* Création du calculateur */
    ComputationAgent calculateur;

    /* Création des structures de données */
    calculateur.loadData();


    /* Création de l'utilisateur */
    User admin = Admin("toto.samain@insa-lyon.fr", "password", &calculateur);


    /* Affichage des données récupérées */
    // Sensor:
    unordered_map<int, Sensor*> &sensors = calculateur.getHmapIdSensor();
    map<pair<double, double>, vector<Sensor*>> &sensors2 = calculateur.getMapCoordSensor();
    int nbSensors = sensors.size();
    cout << "Liste des capteurs : " << endl;
    for (auto sensor : sensors) {
        cout << "id: " << sensor.first << " Sensor: " << *sensor.second << endl;
    }
    cout << "Nombre de capteurs : " << nbSensors << endl;

    cout << "Liste des capteurs selon la lat et long: " << endl;
    for (auto sensor : sensors2) {
        cout << "lat: " << sensor.first.first << " long: " << sensor.first.second << " Sensors: ";
        for (auto s : sensor.second) {
            cout << *s << " ";
        }
        cout << endl;
    }

    cout << "Test ComputeSensorAnalysed: " << calculateur.ComputeSensorAnalysed(14, 4.0, calculateur);

    return 0;
}