//---------- Réalisation de la classe <ComputationAgent> (fichier ComputationAgent.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ComputationAgent.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

ComputationAgent::ComputationAgent ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <ComputationAgent>" << endl;
#endif

} //----- Fin de ComputationAgent défaut

ComputationAgent::ComputationAgent (unordered_map<int, Sensor> &sensors, map<pair<double, double>, vector<Sensor>> &sensors2)
{
#ifdef MAP
    cout << "Appel au constructeur de <ComputationAgent>" << endl;
#endif
    
        hmapIdSensor = sensors;
        mapCoordSensor = sensors2;
    
} //----- Fin de ComputationAgent



ComputationAgent::~ComputationAgent ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <ComputationAgent>" << endl;
#endif

} //----- Fin de ~ComputationAgent


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
