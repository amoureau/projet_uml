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
#include "Timestamp.h"
#include "Provider.h"

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



    // getter setter

    // stockage de base

    unordered_map<int, Sensor*>& getHmapIdSensor()
    {
        return hmapIdSensor;
    }
    

    unordered_map<int, PrivateIndividual*>& getHmapIdPrivateIndividual()
    {
        return hmapIdPrivateIndividual;
    }

    unordered_map<string, Attributes*>& getHmapAttributes()
    {
        return hmapAttributes;
    }

    vector<Measurement*>& getVecteurMeasurements()
    {
        return vecteurMeasurements;
    }

    unordered_map<int, Cleaner*>& getHmapIdCleaner()
    {
        return hmapIdCleaner;
    }

    unordered_map<int, Provider*>& getHmapIdProvider()
    {
        return hmapIdProvider;
    }

    // lien - structure de données annexe

    unordered_map<int, PrivateIndividual*>& getHmapIdSensorPrivateIndividual()
    {
        return hmapIdSensorPrivateIndividual;
    }   

    unordered_map<string, Attributes*>& getHmapDescriptionAttributes()
    {
        return hmapDescriptionAttributes;
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
    vector<Measurement*> vecteurMeasurements;
    unordered_map<int, Cleaner*> hmapIdCleaner;
    unordered_map<int, Provider*> hmapIdProvider;

    // lien - structure de données annexe
    map<pair<double, double>, vector<Sensor*>> mapCoordSensor; 
    unordered_map<int, PrivateIndividual*> hmapIdSensorPrivateIndividual; 
    unordered_map<string, Attributes*> hmapDescriptionAttributes;

private:
    void loadSensor(void);
    void loadPrivateIndividual(void);
    void loadAttributes(void);
    void loadMesurements(void);
    void loadCleaner(void);
    void loadProvider(void);

};

//-------------------------------- Autres définitions dépendantes
#endif 
