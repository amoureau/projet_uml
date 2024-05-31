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
double Measurement::getValue() const
{
    return value;
}

Timestamp Measurement::getDate() const
{
    return date;
}

Sensor* Measurement::getSensor() const
{
    return sensor;
}

Attributes* Measurement::getAttribute() const
{
    return attribute;
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif

} //----- Fin de Measurement

Measurement::Measurement (double value, Timestamp date, Sensor* sensor, Attributes* attribute) : value(value), date(date), sensor(sensor), attribute(attribute)
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