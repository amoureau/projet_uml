//---------- Interface de la classe <ComputationAgent> (fichier ComputationAgent.h)  ----------------
#if ! defined ( COMPUTATIONAGENT_H )
#define COMPUTATIONAGENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <sstream>

#include "Measurement.h"
#include "Cleaner.h"
#include "Sensor.h"
#include "Attributes.h"
#include "PrivateIndividual.h"
#include "Results.h"
#include "TimeStamp.h"

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
    // chargement des données
    void loadData(void);
    
    int ComputeMeanQuality(double latitude, double longitude, double radius, TimeStamp startTime, TimeStamp endTime);


    // getter setter
    unordered_map<int, Sensor*>& getHmapIdSensor()
    {
        return hmapIdSensor;
    }
    map<pair<double, double>, vector<Sensor*>>& getMapCoordSensor()
    {
        return mapCoordSensor;
    }   


//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    ComputationAgent ();    


    virtual ~ComputationAgent ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    // stockage de base
    unordered_map<int, Sensor*> hmapIdSensor;
    unordered_map<int, PrivateIndividual*> hmapIdPrivateIndividual;
    unordered_map<string, Attributes*> hmapAttributes;

    // lien - structure de données annexe
    map<pair<double, double>, vector<Sensor*>> mapCoordSensor; 
    unordered_map<int, PrivateIndividual*> hmapIdSensorPrivateIndividual; 

private:
    void loadSensor(void);
    void loadPrivateIndividual(void);
    void loadAttributes(void);

};

//-------------------------------- Autres définitions dépendantes
#endif 
