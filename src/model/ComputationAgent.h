//---------- Interface de la classe <ComputationAgent> (fichier ComputationAgent.h)  ----------------
#if ! defined ( COMPUTATIONAGENT_H )
#define COMPUTATIONAGENT_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include <string>
#include <utility>
#include <list>
#include <cmath>
#include <ctime>

#include "Measurement.h"
#include "Cleaner.h"
#include "Attributes.h"
#include "Sensor.h"

using namespace std;
//------------------------------------------------------------- Constantes
const double RAYON_TERRE = 63710.0; //km
const double PI = 3.1415926;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
//------------------------------------------------------------------------

class ComputationAgent 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques

static pair<bool, list<double>> ComputeSensorAnalysed() {

}

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    ComputationAgent ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~ComputationAgent ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
double ComputeMeanForAnAttribute (double latitude, double longitude, Attributes attribute, double radius, time_t startTime, time_t endTime) {
    list<Sensor> sensorsDansZone;

    for (Sensor sensor: listSensors) {
        if (calculateDistance( latitude, longitude, sensor.getLatitude(), sensor.getLongitude() ) < radius) {
            sensorsDansZone.push_back( sensor );
        }    
    }

    double moyenne = 0;
    for (Measurement m : listMeasurements) {
        time_t mesureTime = stringToTime(m.getDate());
        if ( m.getAttributes() == attribute && difftime(mesureTime, startTime) > 0 && difftime(mesureTime, endTime) < 0) {
            for (Sensor sensor: sensorsDansZone) {
                if (m.getSensor() == sensor) {
                    moyenne += m.getValue();
                }
            }
        }
    }
}

time_t stringToTime(string str_time) {
    struct tm tm;
    int year, month, day, hour, minute, second;
    sscanf(str_time.c_str(), "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_isdst = -1; // Let the system determine if DST is in effect
    time_t time = mktime(&tm);
    return time;
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double lat1_rad = toRadians(lat1);
    double lon1_rad = toRadians(lon1);
    double lat2_rad = toRadians(lat2);
    double lon2_rad = toRadians(lon2);

    double dlon = lon2_rad - lon1_rad;
    double dlat = lat2_rad - lat1_rad;
    double a = sin( dlat / 2 ) * sin( dlat / 2) + cos(lat1) * cos (lat2) * sin(dlon / 2) * sin( dlon / 2);
    double c = 2 * atan2( sqrt(a), sqrt(1-a));
    return RAYON_TERRE * c;
}

double toRadians(double degrees) {
    return degrees * (PI / 180);
}
//----------------------------------------------------- Attributs protégés
    list<Measurement> listMeasurements;
    list<Cleaner> listCleaners;
    list<Sensor> listSensors;
    list<Attributes> listAttributes;
};

//-------------------------------- Autres définitions dépendantes
#endif 
