//---------- Réalisation de la classe <Results> (fichier Results.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Results.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void Results::GreetingsUser(User user)  // Fonction pour saluer l'utilisateur
{
    string email = user.getEmail();
    string prenom = email.substr(0, email.find('.'));
    cout << "Bonjour " << prenom << " !" << endl;
}

string Results::GetUserInput() { // Fonction générale pour récupérer l'input de l'utilisateur
    string input;                // préférable d'utiliser les fonctions spécifiques ci-dessous
    cout << "Que souhaitez-vous faire ?" << endl;
    cin >> input;
    return input;
} 

string Results::GetInputFonctionnalite() { // Fonction pour récupérer l'input de la fonctionnalité souhaitée
    string fonctionnalite;
    cout << "Quelle fonctionnalité souhaitez-vous utiliser ?" << endl;
    cout << "1. Analyser la qualité de l'air" << endl;
    cout << "2. Analyser un capteur" << endl;
    cout << "Entrer le numéro correspondant à la fonctionnalité souhaitée :";
    cin >> fonctionnalite;
    return fonctionnalite;
}

string Results::GetInputIdSensor() { // Fonction pour récupérer l'input de l'identifiant du capteur
    string idSensor;
    cout << "Quel est l'identifiant du capteur que vous souhaitez analyser ?" << endl;
    cout << "Entrer l'identifiant du capteur :";
    cin >> idSensor;
    return idSensor;
}

string Results::GetInputTimeChoice() { // Fonction pour récupérer si l'utilisateur souhaite analyser la qualité de l'air sur une période précise ou non
    string time;
    cout << "Souhaitez vous analyser la qualité de l'air sur une période précise ?" << endl;
    cout << "Si oui, veuillez entrer 1" << endl;
    cout << "Si non, veuillez entrer 0" << endl;
    cin >> time;
    return time;
}

string Results::GetInputStartTime() { // Fonction pour récupérer l'input de la date de début de la période
    string date;
    cout << "Veuillez entrer la date de début de la période souhaitée" << endl;
    cout << "Format : aaaa-mm-jj h:m:s" << endl;
    cin >> date;
    return date;
}

string Results::GetInputEndTime() { // Fonction pour récupérer l'input de la date de fin de la période
    string date;
    cout << "Veuillez entrer la date de fin de la période souhaitée" << endl;
    cout << "Format : aaaa-mm-jj h:m:s" << endl;
    cin >> date;
    return date;
}

string Results::Print(string message) { // Fonction pour afficher un message
    cout << message << endl;
}

string Results::DisplayMeanAirQuality(double mean) { // Fonction pour afficher la qualité de l'air moyenne
    cout << "La qualité de l'air moyenne est de " << mean << endl;
}

string Results::DisplaySensorAnalysed(bool anomalie) { // Fonction pour afficher si un capteur est anormal ou non
    if(anomalie) {
        cout << "Il y a une anomalie sur le capteur analysé" << endl;
    } else {
        cout << "Il n'y a pas d'anomalie sur le capteur analysé" << endl;
    }
}

Results::Results()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Results>" << endl;
#endif

}

Results::~Results()
{
#ifdef MAP
    cout << "Appel au destructeur de <Results>" << endl;
#endif
}

