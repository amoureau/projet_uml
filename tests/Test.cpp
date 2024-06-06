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
void Test::testAll() {
    testCalculateDistance();
    testComputeSensorAnalyse();
    testComputeMeanQuality();
    testIndiceCorrespondingToMean();
    testComputeMeanForAnAttribute();
}

void Test::testCalculateDistance() {
    cout << "----------------------------------------------------------\n";
    cout << "Test fonction: CalculateDistance( lat1, lng1, lat2, lng2 )" << endl;
    int nbTest = 5;
    int testPassed = 0;

    if (CD_cas1_entree_valide()) testPassed++;
    if (CD_cas2_entree_valide()) testPassed++;
    if (CD_cas3_entree_valide_2_points_egaux()) testPassed++;
    if (CD_cas4_entree_lat_invalide()) testPassed++;
    if (CD_cas5_entree_lng_invalide()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!\n" << endl;
}

void Test::testComputeSensorAnalyse() {
    cout << "----------------------------------------------------------\n";
    cout << "Test fonction: ComputeSensorAnalyse( idSensor, areaRadius )" << endl;
    int nbTest = 8;
    int testPassed = 0;

    if (CSA_cas1_meme_molecule_capteur_trucque()) testPassed++;
    if (CSA_cas2_meme_molecule_capteur_non_truque()) testPassed++;
    if (CSA_cas3_plusieur_molecule_capteur_non_truque()) testPassed++;
    if (CSA_cas4_plusieur_molecule_capteur_truque()) testPassed++;
    if (CSA_cas5_voisin_meme_molecule_capteur_non_truque()) testPassed++;
    if (CSA_cas6_voisin_meme_molecule_capteur_truque()) testPassed++;
    if (CSA_cas7_non_voisin()) testPassed++;
    if (CSA_cas8_non_voisin_avec_meme_molecule()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!\n" << endl;
}

void Test::testComputeMeanQuality() {
    cout << "----------------------------------------------------------\n";
    cout << "Test fonction: ComputeMeanQuality(latitude, longitude, radius, startTime, endTime):" << endl;
    int nbTest = 9;
    int testPassed = 0;

    if (CMQ_case1_testDeBase()) testPassed++;
    if (CMQ_case2_filtrageDate()) testPassed++;
    if (CMQ_case3_filtragePosition()) testPassed++;
    if (CMQ_case4_manqueUneMolecule()) testPassed++;
    if (CMQ_case5_rayonInvalide()) testPassed++;
    if (CMQ_case6_latitudeInvalide()) testPassed++;
    if (CMQ_case7_longitudeInvalide()) testPassed++;
    if (CMQ_case8_DatesInvalide()) testPassed++;
    if (CMQ_case9_MesureInvalide()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!\n" << endl;
}

void Test::testIndiceCorrespondingToMean() {
    cout << "----------------------------------------------------------\n";
    cout << "Test fonction: indiceCorrespondingToMean(molecule, moyenne):" << endl;
    int nbTest = 4;
    int testPassed = 0;

    if (ICTM_case1_TestForO3()) testPassed++;
    if (ICTM_case2_TestForSO2()) testPassed++;
    if (ICTM_case3_TestForNO2()) testPassed++;
    if (ICTM_case4_TestForPM10()) testPassed++;

    cout << testPassed << "/" << nbTest << " tests réussis!\n" << endl;
}

void Test::testComputeMeanForAnAttribute() {
    cout << "----------------------------------------------------------\n";
    cout << "Test fonction: ComputeMeanForAnAttribute(latitude, longitude, molecule, radius, startTime, endTime):" << endl;
    int nbTest = 10;
    int testPassed = 0;

    if (CMFAA_case1_MeanForO3()) testPassed++;
    if (CMFAA_case2_FiltrageDate()) testPassed++;
    if (CMFAA_case3_FiltragePosition()) testPassed++;
    if (CMFAA_case4_FiltrageMoleculeErreurPasMesure()) testPassed++;
    if (CMFAA_case5_RayonIncorrect()) testPassed++;
    if (CMFAA_case6_LatitudeIncorrecte()) testPassed++;
    if (CMFAA_case7_LongitudeIncorrecte()) testPassed++;
    if (CMFAA_case8_DatesIncorrectes()) testPassed++;
    if (CMFAA_case9_MesureInvalide()) testPassed++;
    if (CMFAA_case10_MoleculeExistePas()) testPassed++;


    cout << testPassed << "/" << nbTest << " tests réussis!\n" << endl;
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