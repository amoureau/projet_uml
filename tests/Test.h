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
    void testCalculateDistance();
    void testComputeSensorAnalyse();

//----------------------------------------------------- MÃ©thodes publiques
    // static void testComputeSensorAnalysed() {
    //     cout << "Test pour fonction: computeSensorAnalysed" <<endl;

    //     int numberTestCase = 1;
    //     int countTestPassed = 0;
    //     for (int i = 1; i <= numberTestCase; i++) {
    //         string dataChemin = "dataset/tests/computeSensorAnalyse/test" + to_string(i);
        
    //         ComputationAgent *calculateur = new ComputationAgent();
    //         calculateur->loadTestData(dataChemin);

    //         string args[2];
    //         string res;
    //         getArgumentsAndResult(dataChemin, args, res);
    //         cout << res << endl;

    //         bool funcReturn = calculateur->ComputeSensorAnalysed( stoi(args[0]), stod(args[1]) );
    //         if (funcReturn == stoi(res)) {
    //             cout << "Test " + to_string(i) + " passed!" << endl;
    //             countTestPassed++;
    //         } else {
    //             cout << "Test " + to_string(i) + " fail!" << endl;
    //             cout << "    Expected: " + res << endl << "    Get: " << funcReturn << endl;
    //         }

    //         delete calculateur;
    //     }
    //     cout << countTestPassed << "/" << numberTestCase << " passed";
    // }

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
    bool CSA_cas1_meme_molecule();

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
