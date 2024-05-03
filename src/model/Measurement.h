//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
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
    double getValue() const;
    string getDate() const;
    Sensor getSensor() const;
    Attributes getAttributes() const;
//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Measurement ();
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
    string date;
    Sensor sensor;
    Attributes Attributes;
};

//-------------------------------- Autres définitions dépendantes
#endif 
