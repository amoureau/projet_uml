//---------- Interface de la classe <Results> (fichier Results.h) ----------------
#if ! defined ( RESULTS_H )
#define RESULTS_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <iostream>
#include "Controller.h"
#include "Timestamp.h"

class Controller;
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Results 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur
    void GreetingsUser(User user, string role);

    string GetUserInput();

    int GetInputFonctionnalite(string role);

    int GetInputLatitude();

    int GetInputLongitude();

    int GetInputIdSensor();

    int GetInputAreaRadius();

    int GetInputTimeChoice();

    Timestamp GetInputStartTime();

    Timestamp GetInputEndTime();

    void Print(string message);

    void DisplayMeanAirQuality(double mean);

    void DisplaySensorAnalysed(bool anomalie);

    Results();

    virtual ~Results ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    Controller *controller;
};

//-------------------------------- Autres définitions dépendantes
#endif
