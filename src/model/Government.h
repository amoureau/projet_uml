//---------- Interface de la classe <Government> (fichier Government.h) ----------------
#if ! defined ( GOVERNMENT_H )
#define GOVERNMENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <utility>
#include <list>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Government 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Government ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~Government ( );
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
