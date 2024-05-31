//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include "Timestamp.h"
#include "Sensor.h"
#include "Attributes.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    Timestamp getDate() const {
        return date;
    }
    Attributes* getAttribute() const {
        return attribute;
    }
    Sensor* getSensor() const {
        return sensor;
    }
    double getValue() const {
        return value;
    }
//------------------------------------------------- Surcharge d'opÃ©rateurs

    friend ostream& operator<<(ostream& os, const Measurement& measurement)
    {
        os << "Measurement: value:" << measurement.value << " date:" << measurement.date << " sensor:" << *(measurement.sensor) << " attribute:" << *(measurement.attribute);
        return os;
    }

//-------------------------------------------- Constructeurs - destructeur

    Measurement ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    Measurement (double value, Timestamp date, Sensor* sensor, Attributes* attribute);
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~Measurement ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    double value;
    Timestamp date;
    Sensor* sensor;
    Attributes* attribute;
};

//-------------------------------- Autres définitions dépendantes
#endif 