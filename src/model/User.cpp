<<<<<<< HEAD
//---------- RÃ©alisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

User::User ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
this->calculateur = ComputationAgent();

} //----- Fin de User


User::~User ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

=======
//---------- RÃ©alisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

User::User ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
this->calculateur = ComputationAgent();

} //----- Fin de User


User::~User ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

>>>>>>> 9283a13b957d47948a4af492676ebbdc42a9b3c4
//----------------------------------------------------- MÃ©thodes protégées