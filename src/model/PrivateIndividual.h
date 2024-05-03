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

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    PrivateIndividual ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~PrivateIndividual ( );
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
