#include "Test.h"


// Fichier contenant les méthodes de tests pour la fonction indiceCorrespondingToMean

/*

Signature : indiceCorrespondingToMean(string attribut, double moyenne)

Description :  Renvoie l’indice ATMO (de France de 2014 -> 10 niveaux par molécule) 
               correspondant à la molécule et à la moyenne des valeurs données en paramètres

*/

bool Test::ICTM_case1_TestForO3(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Test pour O3
    */
    cout << "Cas 1: Test pour O3. ";

    ComputationAgent *calculateur = new ComputationAgent();
    int sortie_attendue = 10;
    int sortie_obtenue = calculateur->indiceCorrespondingToMean("O3", 240.0);

    bool result = sortie_obtenue == sortie_attendue;
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }

    return result ;
}

bool Test::ICTM_case2_TestForSO2(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Test pour SO2
    */
    cout << "Cas 2: Test pour SO2. ";
    ComputationAgent *calculateur = new ComputationAgent();
    int sortie_attendue = 6;
    int sortie_obtenue = calculateur->indiceCorrespondingToMean("SO2", 240.0);

    bool result = sortie_obtenue == sortie_attendue;
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;

}

bool Test::ICTM_case3_TestForNO2(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Test pour NO2
    */

    cout << "Cas 3: Test pour NO2. ";

    ComputationAgent *calculateur = new ComputationAgent();
    int sortie_attendue = 8;
    int sortie_obtenue = calculateur->indiceCorrespondingToMean("NO2", 240.0);

    bool result = sortie_obtenue == sortie_attendue;
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;

}
bool Test::ICTM_case4_TestForPM10(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Test pour PM10
    */
    cout << "Cas 1: Test pour PM10. ";

    ComputationAgent *calculateur = new ComputationAgent();
    int sortie_attendue = 10;
    int sortie_obtenue = calculateur->indiceCorrespondingToMean("PM10", 240.0);

    bool result = sortie_obtenue == sortie_attendue;
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

