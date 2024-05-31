//---------- Interface de la classe <Attributes> (fichier Attributes.h) ----------------
#if ! defined ( ATTRIBUTES_H )
#define ATTRIBUTES_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Attributes 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    string getDescription() const {
        return description;
    }
    string getId() const {
        return id;
    }
    string getUnit() const {
        return unit;
    }

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Attributes ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    Attributes(string id, string unit, string description);

    virtual ~Attributes ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string id;
    string unit;
    string description;
};

//-------------------------------- Autres définitions dépendantes
#endif 
