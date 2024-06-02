//---------- Interface de la classe <Test> (fichier Test.h) ----------------
#if ! defined ( TEST_H )
#define TEST_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>


#include "ComputationAgent.h"
#include "Timestamp.h"

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
    static void getArgumentsAndResult(string chemin, string* args, string &res) {
        string fichierCSV = chemin + "/arg_res.csv";
        cout << fichierCSV << endl;
        ifstream fichier(fichierCSV);
        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier " << fichierCSV <<  endl;
            exit(1);
        }

        string ligne;

        //get arguments
        getline(fichier, ligne); 
        istringstream iss(ligne);

        string valeur;
        
        // Lecture des valeurs séparées par des points virgules
        int count = 0;
        while (getline(iss, valeur, ';')) {
            args[count] = valeur;
            count++;
        }

        //get result
        getline(fichier, res);
    }

    static void testComputeSensorAnalysed() {
        cout << "Test pour fonction: computeSensorAnalysed" <<endl;

        int numberTestCase = 1;
        int countTestPassed = 0;
        for (int i = 1; i <= numberTestCase; i++) {
            string dataChemin = "dataset/tests/computeSensorAnalyse/test" + to_string(i);
        
            ComputationAgent *calculateur = new ComputationAgent();
            calculateur->loadTestData(dataChemin);

            string args[2];
            string res;
            getArgumentsAndResult(dataChemin, args, res);
            cout << res << endl;

            bool funcReturn = calculateur->ComputeSensorAnalysed( stoi(args[0]), stod(args[1]) );
            if (funcReturn == stoi(res)) {
                cout << "Test " + to_string(i) + " passed!" << endl;
                countTestPassed++;
            } else {
                cout << "Test " + to_string(i) + " fail!" << endl;
                cout << "    Expected: " + res << endl << "    Get: " << funcReturn << endl;
            }

            delete calculateur;
        }
        cout << countTestPassed << "/" << numberTestCase << " passed";
    }

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Test ();
    virtual ~Test ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
