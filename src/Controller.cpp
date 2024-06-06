#include "Controller.h"
#include "../tests/Test.h"



using namespace std;

// Pour les affichages:
void Controller::displayHmapIdSensor()
{
    for(auto it : this->user->getCalculateur()->getHmapIdSensor())
    {
        cout << "Id:" << it.first << ", Sensor:" << *(it.second) << endl;
    }
}

void Controller::displayHmapIdPrivateIndividual()
{
    for(auto it : this->user->getCalculateur()->getHmapIdPrivateIndividual())
    {
        cout << "Id:" << it.first << ", PrivateIndividual:" << *(it.second) << endl;
    }
}

void Controller::displayHmapAttributes()
{
    for(auto it : this->user->getCalculateur()->getHmapAttributes())
    {
        cout << "Id:" << it.first << ", Attributes:" << *(it.second) << endl;
    }
}

void Controller::displayHmapIdCleaner()
{
    for(auto it : this->user->getCalculateur()->getHmapIdCleaner())
    {
        cout << "Id:" << it.first << ", Cleaner:" << *(it.second) << endl;
    }
}

void Controller::displayHmapIdProvider()
{
    for(auto it : this->user->getCalculateur()->getHmapIdProvider())
    {
        cout << "Id:" << it.first << ", Provider:" << *(it.second) << endl;
    }
}

void Controller::displayHmapIdSensorPrivateIndividual()
{
    for(auto it : this->user->getCalculateur()->getHmapIdSensorPrivateIndividual())
    {
        cout << "Id:" << it.first << ", sensor:" << *(it.second) << endl;
    }
}


void Controller::displayHmapDescriptionAttributes()
{
    for(auto it : this->user->getCalculateur()->getHmapDescriptionAttributes())
    {
        cout << "Description:" << it.first << ", Attributes:" << *(it.second) << endl;
    }
}
void Controller::displayVecteurMeasurements()
{
    for(auto it : this->user->getCalculateur()->getVecteurMeasurements())
    {
        cout << "Measurement:" << *it << endl;
    }
}


void Controller::displayMapCoordSensor()
{
    for(auto it : this->user->getCalculateur()->getMapCoordSensor())
    {
        cout << "CoordSensor:" << it.first.first << " " << it.first.second << endl;
        for(auto it2 : it.second)
        {
            cout << "Sensor:" << *it2 << endl;
        }
    }
}



// - fin affichage



Controller::Controller(){
    /* Création du calculateur */
    ComputationAgent *calculateur = new ComputationAgent();

    /* Création des structures de données */
    calculateur->loadData();

    /* Création de l'utilisateur */
    User *admin = new Admin("toto.samain@insa-lyon.fr", "password", calculateur); // a la place du log in normalement

    /* Création du résultat */
    Results *result = new Results();

    this->user = admin;
    this->result = result;
}

Controller::~Controller(){
    delete user;
    delete result;
}

int Controller::mainController(void)
{
    // Affichage des données
    // displayHmapIdSensor();
    // displayHmapIdPrivateIndividual();
    // displayHmapAttributes();
    // displayVecteurMeasurements();
    // displayHmapIdCleaner();
    // displayHmapIdProvider();
    // displayMapCoordSensor();
    // displayHmapIdSensorPrivateIndividual();
    // displayHmapDescriptionAttributes();


    int userInput = -1;

    string role = "user";
    if (dynamic_cast<Admin*>(user)) {
        role = "admin";
    } else if (dynamic_cast<Government*>(user)) {
        role = "government";
    } else if (dynamic_cast<PrivateIndividual*>(user)) {
        role = "private individual";
    } else if (dynamic_cast<Provider*>(user)) {
        role = "provider";
    }

    result->GreetingsUser(user, role);
    int radius, latitude, longitude, timeChoice, idSensor, radiusSensor;
    while(userInput != 0)
    {
        userInput = result->GetInputFonctionnalite(role);
        switch(userInput)
        {
            case 0:
                // Quitter
                cout << "Au revoir !" << endl;
                break;
            case 1:
                // Analyser la qualité de l'air
                radius = result->GetInputAreaRadius();
                latitude = result->GetInputLatitude();
                longitude = result->GetInputLongitude();
                timeChoice = result->GetInputTimeChoice();
                switch(timeChoice) {
                    case 0:
                        // Analyse sur une période de temps
                        result->DisplayMeanAirQuality(user->getCalculateur()->ComputeMeanQuality(latitude, longitude, radius,0,0));
                        break;
                    case 1:
                        // Analyse sur une période de temps
                        Timestamp startTime = result->GetInputStartTime();
                        Timestamp endTime = result->GetInputEndTime();
                        result->DisplayMeanAirQuality(user->getCalculateur()->ComputeMeanQuality(latitude, longitude, radius, startTime, endTime));
                        break;         
                }
                break;
            case 2:
                // Analyser un capteur
                idSensor = result->GetInputIdSensor(); 
                radius = result->GetInputAreaRadius();
                bool anomalie = user->getCalculateur()->ComputeSensorAnalysed(idSensor, radius);
                result->DisplaySensorAnalysed(anomalie); //affiche toujours qu'il y a une anomalie donc je pense que y'a un bug dans les fonctions
                break;
        }
    }

    return 0;

}



int main(int argc, char *argv[])
{
    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "test" || mode == "Test") {
            Test *test = new Test();
            test->testAll();
            delete test;
            return 0;
        }
    }

    Controller *controller = new Controller();
    controller->mainController();
    delete controller;
    return 0;
}