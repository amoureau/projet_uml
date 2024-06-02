#include "Test.h"

// Fichier contenant les méthodes de tests pour la fonction ComputeMeanForAnAttribute

bool Test::CSA_cas1_meme_molecule() {
    ComputationAgent *calculateur = new ComputationAgent();

    Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
    Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
    Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
    Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

    Sensor *sensor1 = new Sensor( 1, 44.0, -1.0, nullptr );
    Sensor *sensor2 = new Sensor( 2, 44.0, -1.0, nullptr );
    Sensor *sensor3 = new Sensor( 3, 44.0, -1.0, nullptr );
    Sensor *sensor4 = new Sensor( 4, 44.0, -1.0, nullptr );
    calculateur->hmapIdSensor[1] = sensor1;
    calculateur->hmapIdSensor[2] = sensor2;
    calculateur->hmapIdSensor[3] = sensor3;
    calculateur->hmapIdSensor[4] = sensor4;

    Measurement* m1 = new Measurement(10.0, Timestamp("2019-01-01 01:00:00"), sensor1,  O3);
    Measurement* m2 = new Measurement(50.0, Timestamp("2019-01-01 01:00:00"), sensor2,  O3);
    Measurement* m3 = new Measurement(50.0, Timestamp("2019-01-01 01:00:00"), sensor3,  O3);
    Measurement* m4 = new Measurement(50.0, Timestamp("2019-01-01 01:00:00"), sensor4,  O3);
    calculateur->vecteurMeasurements.push_back(m1);
    calculateur->vecteurMeasurements.push_back(m2);
    calculateur->vecteurMeasurements.push_back(m3);
    calculateur->vecteurMeasurements.push_back(m4);

    bool sortie_attendue = true;
    bool sortie_obtenue = calculateur->ComputeSensorAnalysed(1, 1.0);

    bool result = sortie_attendue == sortie_obtenue;
    if (result) {
        cout << "Cas 1: entree validee. Reussi!" << endl;
    } else {
        cout << "Cas 1: entree validee. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}