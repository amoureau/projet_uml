//---------- Interface de la classe <ComputationAgent> (fichier ComputationAgent.h)  ----------------
#if ! defined ( COMPUTATIONAGENT_H )
#define COMPUTATIONAGENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#include "Measurement.h"
#include "Cleaner.h"
#include "Sensor.h"
#include "Attributes.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class ComputationAgent 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    ComputationAgent ();
    ComputationAgent (unordered_map<int, Sensor> &sensors, map<pair<double, double>, vector<Sensor>> &sensors2);
    


    virtual ~ComputationAgent ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    unordered_map<int, Sensor> hmapIdSensor;
    map<pair<double, double>, vector<Sensor>> mapCoordSensor;

};

//-------------------------------- Autres définitions dépendantes
#endif 
