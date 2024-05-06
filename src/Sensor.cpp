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

int Sensor::getId() const
{
    return id;
}

double Sensor::getLatitude() const
{
    return latitude;
}

double Sensor::getLongitude() const
{
    return longitude; // salut
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::Sensor(int id, double latitude, double longitude) : id(id), latitude(latitude), longitude(longitude)
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

} //----- Fin de Sensor

Sensor::Sensor(const Sensor& unSensor) : id(unSensor.id), latitude(unSensor.latitude), longitude(unSensor.longitude)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    
} //----- Fin de Sensor


Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur par défaut de <Sensor>" << endl;
#endif

} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
