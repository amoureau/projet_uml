#include "Controller.h"



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
    //displayHmapIdSensor();
    //displayHmapIdPrivateIndividual();
    //displayHmapAttributes();
    //displayVecteurMeasurements();
    //displayHmapIdCleaner();
    //displayHmapIdProvider();
    //displayMapCoordSensor();
    //displayHmapIdSensorPrivateIndividual();
    //displayHmapDescriptionAttributes();


    string userInput = "";
    while(userInput != "exit")
    {
        result->GreetingsUser(user);
        userInput = result->GetUserInput();
        switch(userInput)
        {
            case "DisplayMeanQuality":
                user
                break;
        }
    }

    return 0;

}



int main(void)
{
    Controller *controller = new Controller();
    controller->mainController();
    delete controller;
    return 0;
}