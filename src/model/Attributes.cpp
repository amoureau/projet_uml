//---------- Réalisation de la classe <Attributes> (fichier Attributes.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attributes.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Attributes::Attributes ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Attributes>" << endl;
#endif

} //----- Fin de Attributes


Attributes::~Attributes ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Attributes>" << endl;
#endif

} //----- Fin de ~Attributes


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
