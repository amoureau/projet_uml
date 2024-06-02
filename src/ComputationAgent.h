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
#include <cmath>

#include "Measurement.h"
#include "Cleaner.h"
#include "Sensor.h"
#include "Attributes.h"
#include "PrivateIndividual.h"

#include "Timestamp.h"
#include "Provider.h"

using namespace std;
//------------------------------------------------------------- Constantes
const double RAYON_TERRE = 6371.0; //km
const double PI = 3.1415926;
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
    
    int ComputeMeanQuality(double latitude, double longitude, double radius, Timestamp startTime, Timestamp endTime);

    bool ComputeSensorAnalysed(int sensorId, double areaRadius);

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

    static double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
        double dlon = toRadians(lon2 - lon1);
        double dlat = toRadians(lat2 - lat1);
        double a = sin( dlat / 2 ) * sin( dlat / 2) + cos(toRadians(lat1)) * cos (toRadians(lat2)) * sin(dlon / 2) * sin( dlon / 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a));
        return RAYON_TERRE * c;
    }

    static double toRadians(double degrees) {
        return degrees * (PI / 180);
    }

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    ComputationAgent ();    


    virtual ~ComputationAgent ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


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

    int indiceCorrespondingToMean(string attribut, double moyenne);
    double ComputeMeanForAnAttribute ( double latitude, double longitude, string& attribut, double radius, Timestamp startTime, Timestamp endTime);
};

//-------------------------------- Autres définitions dépendantes
#endif 
