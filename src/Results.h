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
    void GreetingsUser(User user);

    string GetUserInput();

    string GetInputFonctionnalite();

    string GetInputIdSensor();

    string GetInputTimeChoice();

    string GetInputStartTime();

    string GetInputEndTime();

    string Print(string message);

    string DisplayMeanAirQuality(double mean);

    string DisplaySensorAnalysed(bool anomalie);

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
