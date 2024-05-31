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

//------------------------------------------------- Surcharge d'opÃ©rateurs

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
