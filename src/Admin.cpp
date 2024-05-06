//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Admin.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Admin::Admin ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Admin>" << endl;
#endif

} //----- Fin de Admin

Admin::Admin(string email, string password, ComputationAgent *calculateur) : User(email, password, calculateur)
{
#ifdef MAP
    cout << "Appel au constructeur de <Admin>" << endl;
#endif
    
} //----- Fin de Admin


Admin::~Admin ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Admin>" << endl;
#endif

} //----- Fin de ~Admin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
