//---------- Interface de la classe <Cleaner> (fichier Cleaner.h)  ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include "Timestamp.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Cleaner 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Cleaner ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    Cleaner(double latitude, double longitude, Timestamp dateStart, Timestamp dateEnd);
    // Mode d'emploi : Constructeur

    virtual ~Cleaner ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    double latitude;
    double longitude;
    Timestamp dateStart;
    Timestamp dateEnd;
};

//-------------------------------- Autres définitions dépendantes
#endif 
