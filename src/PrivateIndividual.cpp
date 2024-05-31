//---------- Réalisation de la classe <PrivateIndividual> (fichier PrivateIndividual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivateIndividual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

PrivateIndividual::PrivateIndividual ()
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif

} //----- Fin de PrivateIndividuals

PrivateIndividual::PrivateIndividual(int id) : id(id)
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
    
} //----- Fin de PrivateIndividual

PrivateIndividual::PrivateIndividual(const PrivateIndividual& unPrivateIndividual) : id(unPrivateIndividual.id)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateIndividual>" << endl;
#endif
    
} //----- Fin de PrivateIndividual

PrivateIndividual::~PrivateIndividual ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateIndividual>" << endl;
#endif

} //----- Fin de ~PrivateIndividual


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
