#include "Results.h"

#include "User.h"
#include "Admin.h"
#include "Sensor.h"
#include "ComputationAgent.h"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;


int main(void)
{
    /* Création du calculateur */
    ComputationAgent calculateur;

    /* Création des structures de données */
    calculateur.loadData();


    /* Création de l'utilisateur */
    User admin = Admin("toto.samain@insa-lyon.fr", "password", &calculateur);

    /* Affichage des données récupérées */




    return 0;
}