//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif

} //----- Fin de Measurement

Measurement::Measurement (double value, string date) : value(value), date(date)
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif

} //----- Fin de Measurement

Measurement::~Measurement ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif

} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
