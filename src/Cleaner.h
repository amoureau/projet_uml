//---------- Interface de la classe <Cleaner> (fichier Cleaner.h)  ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include "Timestamp.h"
#include "Provider.h"
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

    // getter:
    int getIdCleaner() const { return idCleaner; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    Timestamp getDateStart() const { return dateStart; }
    Timestamp getDateEnd() const { return dateEnd; }
    const Provider* getProvider() const { return provider; }

    // setter 
    void setProvider(const Provider* provider);




    Cleaner(int idCleaner, double latitude, double longitude, Timestamp dateStart, Timestamp dateEnd, const Provider* provider);
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
    int idCleaner;
    double latitude;
    double longitude;
    Timestamp dateStart;
    Timestamp dateEnd;
    const Provider * provider;
};

//-------------------------------- Autres définitions dépendantes
#endif 
