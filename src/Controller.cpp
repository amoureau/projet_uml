#include "Controller.h"



using namespace std;

// Pour les affichages:
void Controller::displayHmapIdSensor()
{
    for(auto it : this->calculateur->getHmapIdSensor())
    {
        cout << "Id Sensor:" << *(it.second) << endl;
    }
}

void Controller::displayVecteurMeasurements()   {
    vector<Measurement*> measurements = this->calculateur->getVecteurMeasurements();
    for(auto measurement : measurements){
        cout << "Measurement: " << *measurement << endl;
    }
}

void Controller::displayHmapAttributes() {
    for(auto it : this->calculateur->getHmapAttributes())
    {
        cout << "Attribute: " << *(it.second) << endl;
    }
}

void Controller::testComputeSensorAnalysed() {
    cout << "Test Compute Sensor Analysed: " << calculateur->ComputeSensorAnalysed(12, 4.0) << endl;
}




Controller::Controller(){
    /* Création du calculateur */
    ComputationAgent *calculateur = new ComputationAgent();

    /* Création des structures de données */
    calculateur->loadData();

    /* Création de l'utilisateur */
    User *admin = new Admin("toto.samain@insa-lyon.fr", "password", calculateur); // a la place du log in normalement

    /* Création du résultat */
    Results *result = new Results();

    this->calculateur = calculateur;
    this->user = admin;
    this->result = result;
}

Controller::~Controller(){
    delete calculateur;
    delete user;
    delete result;
}

int Controller::mainController(void)
{
    // Affichage des données
    //displayHmapIdSensor();
    //displayHmapAttributes();
    //testComputeSensorAnalysed();

    unordered_map<string, int> test;
    //string t = "ab";
    test["ab"] = 123;
    for (auto t : test) {
        cout << t.first << endl;
        cout << t.second << endl;
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