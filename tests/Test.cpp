//---------- RÃ©alisation de la classe <Test> (fichier Test.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Test.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Test::testCalculateDistance() {
    cout << "Test fonction: CalculateDistance( lat1, lng1, lat2, lng2 )" << endl;
    int nbTest = 5;
    int testPassed = 0;

    if (CD_cas1_entree_valide()) testPassed++;
    if (CD_cas2_entree_valide()) testPassed++;
    if (CD_cas3_entree_valide_2_points_egaux()) testPassed++;
    if (CD_cas4_entree_lat_invalide()) testPassed++;
    if (CD_cas5_entree_lng_invalide()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!" << endl;
}

void Test::testComputeSensorAnalyse() {
    cout << "Test fonction: testComputeSensorAnalyse( idSensor, areaRadius )" << endl;
    int nbTest = 12;
    int testPassed = 0;

    if (CSA_cas1_meme_molecule()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!" << endl;
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Test::Test ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin de Test

Test::~Test ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~Test


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÃ©thodes protégées