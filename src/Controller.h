#if ! defined ( CONTROLLER_H )
#define CONTROLLER_H


#include "ComputationAgent.h"
#include "User.h"
#include "Admin.h"
#include "Results.h"
class Results;




class Controller
{
    public:
        int mainController(void);

        // Affichage:
        /*
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
        */
        
        void displayHmapIdSensor();
        void displayHmapIdPrivateIndividual();
        void displayHmapAttributes();
        void displayVecteurMeasurements();
        void displayHmapIdCleaner();
        void displayHmapIdProvider();
        void displayMapCoordSensor();
        void displayHmapIdSensorPrivateIndividual();
        void displayHmapDescriptionAttributes();

        // fin affichage

        void testComputeSensorAnalysed();

        Controller();
        virtual ~Controller ( );

    private:
        User *user;
        Results *result;
};

#endif