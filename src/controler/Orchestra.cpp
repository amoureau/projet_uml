#include "../view/Results.h"

#include "../model/User.h"
#include "../model/Admin.h"
#include "../model/Sensor.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Définition d'un objet "Personne" avec des attributs nom, prénom et âge


static void sensorsDATA(void)

// Fonction pour charger un fichier CSV et le découper en objets "Personne"
void loadData(void) {

    // chemins acces fichiers:
    string sensorsCSV = "../../dataset/sensors.csv";


    vector<string> listCSV = {sensorsCSV};


    // liste globale
    vector<Sensor> listSensors;


    for(string fichierCSV :  listCSV)
    {
        ifstream fichier(fichierCSV);
        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
            return personnes;
        }

        string ligne;
        while (getline(fichier, ligne)) {
            istringstream iss(ligne);
            string valeur;
            Personne personne;

            // Lecture des valeurs séparées par des virgules
            getline(iss, valeur, ',');
            personne.nom = valeur;
            getline(iss, valeur, ',');
            personne.prenom = valeur;
            getline(iss, valeur, ',');
            personne.age =  stoi(valeur);

            personnes.push_back(personne);
        }
    }

    fichier.close();

}




int main(void)
{
    User currUser = Admin();

    loadData();


    return 0;
}