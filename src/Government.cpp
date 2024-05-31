//---------- Réalisation de la classe <Government> (fichier Government.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Government.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Government::Government ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Government>" << endl;
#endif

} //----- Fin de Government


Government::~Government ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Government>" << endl;
#endif

} //----- Fin de ~Government


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
