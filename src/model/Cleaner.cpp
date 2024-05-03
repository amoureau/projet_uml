//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif

} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif

} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
