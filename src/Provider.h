//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class Provider 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

//------------------------------------------------- Surcharge d'opÃ©rateurs

    friend ostream& operator<<(ostream& os, const Provider& provider)
    {
        os << "Provider: idProvider:" << provider.idProvider;
        return os;
    }

//-------------------------------------------- Constructeurs - destructeur

    Provider ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    // getter:
    int getIdProvider() const { return idProvider; }


    Provider(int idProvider);
    // Mode d'emploi : Constructeur
    
    virtual ~Provider ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    int idProvider;
};

//-------------------------------- Autres définitions dépendantes
#endif 
