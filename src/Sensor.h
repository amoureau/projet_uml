//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <iostream>
#include "PrivateIndividual.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    // getter:
    int getId() const { return id; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    const PrivateIndividual* getPrivateIndividual() const { return privateIndividual; }

    // setter
    void setPrivateIndividual(const PrivateIndividual* privateIndividual) { this->privateIndividual = privateIndividual; }




//------------------------------------------------- Surcharge d'opÃ©rateurs
    friend ostream& operator<<(ostream& os, const Sensor& sensor)
    {
        if(sensor.privateIndividual == nullptr)
        {
            os << "Sensor " << sensor.id << " : " << sensor.latitude << " " << sensor.longitude << "  privateIndividual :NULL";
            return os;
        }
        else
            os << "Sensor " << sensor.id << " : " << sensor.latitude << " " << sensor.longitude << " privateIndividual: " << *(sensor.privateIndividual);
        return os;
    }

//-------------------------------------------- Constructeurs - destructeur

    


    Sensor ();
    Sensor(const Sensor& unSensor); // constructeur de copie
    Sensor(int id, double latitude, double longitude, const PrivateIndividual* privateIndividual);
    virtual ~Sensor ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    int id;
    double latitude;
    double longitude;
    const PrivateIndividual* privateIndividual;
};

//-------------------------------- Autres définitions dépendantes
#endif 
