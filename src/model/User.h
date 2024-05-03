//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    double ComputeMeanQualityCircle(double latitude, double longitude, string start, string end);
    // Mode d'emploi : Prend un paramètre de type Trajet * et l'ajoute à la fin de la liste de trajets
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    User ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~User ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>
#endif // Catalogue_H
