//---------- Réalisation de la classe <Results> (fichier Results.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Results.h"
#include "Controller.h"
#include "Timestamp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
Results::Results ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Results>" << endl;
#endif

}

Results::~Results ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Results>" << endl;
#endif
}