//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>


#include "ComputationAgent.h"
#include "Sensor.h"
#include "Timestamp.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    double ComputeMeanQualityCircle(double latitude, double longitude, string start, string end);
    double ComputeWorstQualityDate(Timestamp date);
    pair<double, double>ComputeMaxSurfaceQuality(void);
    double ComputeQualityLocDate(double latitude, double longitude, Timestamp start, Timestamp end);
    map<int, pair<double,double>>ComputeRankedScoredSensor(int idSensor);

//------------------------------------------------- Surcharge d'opÃ©rateurs


//-------------------------------------------- Constructeurs - destructeur

    User ();
    User(string email, string password, ComputationAgent *calculateur);

    virtual ~User ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    ComputationAgent *calculateur;
    string email;
    string password;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
