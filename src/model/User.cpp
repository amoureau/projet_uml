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

//----------------------------------------------------- MÃ©thodes protégées