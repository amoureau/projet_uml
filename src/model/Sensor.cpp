//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

} //----- Fin de Sensor


Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif

} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
