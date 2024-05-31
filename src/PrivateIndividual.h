//---------- Interface de la classe <PrivateIndividual> (fichier PrivateIndividual.h) ----------------
#if ! defined ( PRIVATEINDIVIDUAL_H )
#define PRIVATEINDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>

#include "Sensor.h"

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
    
    PrivateIndividual(const PrivateIndividual& unPrivateIndividual); // constructeur de copie
    PrivateIndividual(int id, Sensor *sensor);

    virtual ~PrivateIndividual ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    int id;
    const Sensor* sensor;


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes
#endif 
