#include "Controller.h"



using namespace std;


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

    return 0;

}



int main(void)
{
    Controller *controller = new Controller();
    delete controller;
    return 0;
}