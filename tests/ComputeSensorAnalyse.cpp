#include "Test.h"

// Fichier contenant les méthodes de tests pour la fonction ComputeMeanForAnAttribute

bool Test::CSA_cas1_meme_molecule_capteur_trucque() {
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
    calculateur->vecteurMeasurements = {m1, m2, m3, m4};

    bool sortie_attendue = true;
    bool sortie_obtenue = calculateur->ComputeSensorAnalysed(1, 1.0);

    bool result = sortie_attendue == sortie_obtenue;
    cout <<"Cas 1: des données sur la même molécule et le capteur est truqué/défectueux. ";
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }

    return result ;
}

bool Test::CSA_cas2_meme_molecule_capteur_non_truque() {
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
    Measurement* m2 = new Measurement(9.0, Timestamp("2019-01-01 01:00:00"), sensor2,  O3);
    Measurement* m3 = new Measurement(10.0, Timestamp("2019-01-01 01:00:00"), sensor3,  O3);
    Measurement* m4 = new Measurement(9.0, Timestamp("2019-01-01 01:00:00"), sensor4,  O3);
    calculateur->vecteurMeasurements = {m1, m2, m3, m4};

    bool sortie_attendue = false;
    bool sortie_obtenue = calculateur->ComputeSensorAnalysed(1, 1.0);

    bool result = sortie_attendue == sortie_obtenue;
    cout << "Cas 2: des données sur la même molécule et le capteur n'est pas truqué/défectueux. ";
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

bool Test::CSA_cas3_plusieur_molecule_capteur_non_truque() {
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
    Sensor *sensor5 = new Sensor( 5, 44.0, -1.0, nullptr );
    Sensor *sensor6 = new Sensor( 6, 44.0, -1.0, nullptr );
    Sensor *sensor7 = new Sensor( 7, 44.0, -1.0, nullptr );
    calculateur->hmapIdSensor[1] = sensor1;
    calculateur->hmapIdSensor[2] = sensor2;
    calculateur->hmapIdSensor[3] = sensor3;
    calculateur->hmapIdSensor[4] = sensor4;
    calculateur->hmapIdSensor[5] = sensor5;
    calculateur->hmapIdSensor[6] = sensor6;
    calculateur->hmapIdSensor[7] = sensor7;

    Measurement* m1 = new Measurement(10.0, Timestamp("2019-01-01 01:00:00"), sensor1,  O3);
    Measurement* m2 = new Measurement(9.0, Timestamp("2019-01-01 01:00:00"), sensor2,  O3);
    Measurement* m3 = new Measurement(10.0, Timestamp("2019-01-01 01:00:00"), sensor3,  O3);
    Measurement* m4 = new Measurement(9.0, Timestamp("2019-01-01 01:00:00"), sensor4,  O3);
    Measurement* m5 = new Measurement(100.0, Timestamp("2019-01-01 01:00:00"), sensor5,  O3);
    Measurement* m6 = new Measurement(150.0, Timestamp("2019-01-01 01:00:00"), sensor6,  O3);
    Measurement* m7 = new Measurement(118.0, Timestamp("2019-01-01 01:00:00"), sensor7,  O3);
    calculateur->vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7};

    bool sortie_attendue = false;
    bool sortie_obtenue = calculateur->ComputeSensorAnalysed(1, 1.0);

    bool result = sortie_attendue == sortie_obtenue;
    cout << "Cas 3: Le capteur n’est pas défectueux et il y a des données de capteurs qui sont voisins mais ne sont pas sur la même molécule. ";
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

bool Test::CSA_cas4_plusieur_molecule_capteur_truque() {
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
    Sensor *sensor5 = new Sensor( 5, 44.0, -1.0, nullptr );
    Sensor *sensor6 = new Sensor( 6, 44.0, -1.0, nullptr );
    Sensor *sensor7 = new Sensor( 7, 44.0, -1.0, nullptr );
    calculateur->hmapIdSensor[1] = sensor1;
    calculateur->hmapIdSensor[2] = sensor2;
    calculateur->hmapIdSensor[3] = sensor3;
    calculateur->hmapIdSensor[4] = sensor4;
    calculateur->hmapIdSensor[5] = sensor5;
    calculateur->hmapIdSensor[6] = sensor6;
    calculateur->hmapIdSensor[7] = sensor7;

    Measurement* m1 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor1,  O3);
    Measurement* m2 = new Measurement(12.0, Timestamp("2019-01-01 01:00:00"), sensor2,  O3);
    Measurement* m3 = new Measurement(13.0, Timestamp("2019-01-01 01:00:00"), sensor3,  O3);
    Measurement* m4 = new Measurement(12.0, Timestamp("2019-01-01 01:00:00"), sensor4,  O3);

    Measurement* m5 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor5,  O3);
    Measurement* m6 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor5,  O3);
    Measurement* m7 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor5,  O3);

    Measurement* m8 = new Measurement(21.0, Timestamp("2019-01-01 01:00:00"), sensor6,  O3);
    Measurement* m9 = new Measurement(21.0, Timestamp("2019-01-01 01:00:00"), sensor6,  O3);
    Measurement* m10 = new Measurement(21.0, Timestamp("2019-01-01 01:00:00"), sensor6,  O3);

    Measurement* m11 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor7,  O3);
    Measurement* m12 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor7,  O3);
    Measurement* m13 = new Measurement(20.0, Timestamp("2019-01-01 01:00:00"), sensor7,  O3);
    calculateur->vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13};

    bool sortie_attendue = true;
    bool sortie_obtenue = calculateur->ComputeSensorAnalysed(1, 1.0);

    cout << "Cas 4: Même cas que cas 3 mais défectueux. ";
    bool result = sortie_attendue == sortie_obtenue;
    if (result) {
        cout << "Reussi!" << endl;
    } else {
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}