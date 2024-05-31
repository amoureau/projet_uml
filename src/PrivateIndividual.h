//---------- Interface de la classe <PrivateIndividual> (fichier PrivateIndividual.h) ----------------
#if ! defined ( PRIVATEINDIVIDUAL_H )
#define PRIVATEINDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class PrivateIndividual 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

// setter getter
    int getId() const { return id; }
    void setId(int id) { this->id = id; }

//------------------------------------------------- Surcharge d'opÃ©rateurs

    friend ostream& operator<<(ostream& os, const PrivateIndividual& privateIndividual)
    {
        os << "PrivateIndividual " << privateIndividual.id;
        return os;
    }

//-------------------------------------------- Constructeurs - destructeur

    PrivateIndividual ();
    
    PrivateIndividual(const PrivateIndividual& unPrivateIndividual); // constructeur de copie
    PrivateIndividual(int id);

    virtual ~PrivateIndividual ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    int id;


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
