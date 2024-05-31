//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Provider::Provider ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::Provider(int idProvider, const Cleaner* cleaner)
{
    this->idProvider = idProvider;
    this->cleaner = cleaner;
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif  
}


Provider::~Provider ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif

} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
