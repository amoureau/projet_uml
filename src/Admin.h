//---------- Interface de la classe <Admin> (fichier Admin.h)  ----------------
#if ! defined ( ADMIN_H )
#define ADMIN_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include "User.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Admin : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Admin ();
    Admin(string email, string password, ComputationAgent *calculateur);

    virtual ~Admin ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
