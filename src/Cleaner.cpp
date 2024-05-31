//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Cleaner.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// setter:
void Cleaner::setProvider(const Provider* provider)
{
    this->provider = provider;
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif

} //----- Fin de Cleaner

Cleaner::Cleaner(int idCleaner, double latitude, double longitude, Timestamp dateStart, Timestamp dateEnd, const Provider* provider)
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    
        this->idCleaner = idCleaner;
        this->latitude = latitude;
        this->longitude = longitude;
        this->dateStart = dateStart;
        this->dateEnd = dateEnd;
        this->provider = provider;
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif

} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
