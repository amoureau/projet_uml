//---------- Interface de la classe <Test> (fichier Test.h) ----------------
#if ! defined ( TEST_H )
#define TEST_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include "../src/ComputationAgent.h"
#include <cstring>
#include <stdexcept>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Test 
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- MÃ©thodes publiques
    void testAll();
    void testCalculateDistance();
    void testComputeSensorAnalyse();
    void testComputeMeanQuality();
    void testIndiceCorrespondingToMean();
    void testComputeMeanForAnAttribute();

    static bool isEgalDouble(double attendue, double obtenue) {
        double ecart = abs(obtenue - attendue);
        if (attendue == 0) {
            return (ecart < 0.5);
        } 
        double relative_ecart = ecart / attendue * 100;
        return relative_ecart < 1;
    }

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Test ();
    virtual ~Test ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
// ---Tests pour Calculate Distance
    bool CD_cas1_entree_valide();
    bool CD_cas2_entree_valide();
    bool CD_cas3_entree_valide_2_points_egaux();
    bool CD_cas4_entree_lat_invalide();
    bool CD_cas5_entree_lng_invalide();

// ---Tests pour Compute Sensor Analyse
    bool CSA_cas1_meme_molecule_capteur_trucque();
    bool CSA_cas2_meme_molecule_capteur_non_truque();
    bool CSA_cas3_plusieur_molecule_capteur_non_truque();
    bool CSA_cas4_plusieur_molecule_capteur_truque();
    bool CSA_cas5_voisin_meme_molecule_capteur_non_truque();
    bool CSA_cas6_voisin_meme_molecule_capteur_truque();
    bool CSA_cas7_non_voisin();
    bool CSA_cas8_non_voisin_avec_meme_molecule();
    // bool CSA_cas9_entree_invalide_rayon_negative();
    // bool CSA_cas10_entree_invalide_capteur_non_existe();
    // bool CSA_cas11_test_filtrage_capteur_non_truque();
    // bool CSA_cas12_test_filtrage_capteur_truque();

// ---Tests pour Compute Mean Quality
    bool CMQ_case1_testDeBase();
    bool CMQ_case2_filtrageDate();
    bool CMQ_case3_filtragePosition();
    bool CMQ_case4_manqueUneMolecule();
    bool CMQ_case5_rayonInvalide();
    bool CMQ_case6_latitudeInvalide();
    bool CMQ_case7_longitudeInvalide();
    bool CMQ_case8_DatesInvalide();
    bool CMQ_case9_MesureInvalide();

// ---Test pour Compute Mean For An Attribute
    bool CMFAA_case1_MeanForO3();
    bool CMFAA_case2_FiltrageDate();
    bool CMFAA_case3_FiltragePosition();
    bool CMFAA_case4_FiltrageMoleculeErreurPasMesure();
    bool CMFAA_case5_RayonIncorrect();
    bool CMFAA_case6_LatitudeIncorrecte();
    bool CMFAA_case7_LongitudeIncorrecte();
    bool CMFAA_case8_DatesIncorrectes();
    bool CMFAA_case9_MesureInvalide();
    bool CMFAA_case10_MoleculeExistePas();

// ---Test pour Indice Corresponding To Mean
    bool ICTM_case1_TestForO3();
    bool ICTM_case2_TestForSO2();
    bool ICTM_case3_TestForNO2();
    bool ICTM_case4_TestForPM10();


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
