//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
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
    int getId() const;
    double getLatitude() const;
    double getLongitude() const;


//------------------------------------------------- Surcharge d'opÃ©rateurs
    friend ostream &operator<<(ostream &os, const Sensor &sensor)
    {
        os << "Sensor " << sensor.id << " : " << sensor.latitude << " " << sensor.longitude;
        return os;
    }
    

//-------------------------------------------- Constructeurs - destructeur

    


    Sensor ();
    Sensor(int id, double latitude, double longitude);
    virtual ~Sensor ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    int id;
    double latitude;
    double longitude;

};

//-------------------------------- Autres définitions dépendantes
#endif 
