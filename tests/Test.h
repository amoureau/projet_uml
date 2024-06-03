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

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
