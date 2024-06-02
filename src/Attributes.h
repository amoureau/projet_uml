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
<<<<<<< HEAD

    friend ostream& operator<<(ostream& os, const Attributes& attributes)
    {
        os << "Attributes: id:" << attributes.id << " unit:" << attributes.unit << " description:" << attributes.description;
        return os;
    }

=======
friend ostream& operator<<(ostream& os, const Attributes& attr) {
    os << "ID: " << attr.id << "; ";
    os << "Unit: " << attr.unit << "; ";
    os << "Description: " << attr.description << endl;
    return os;
}
>>>>>>> test-son
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
