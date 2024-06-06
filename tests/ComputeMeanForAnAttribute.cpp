#include "Test.h"


// Fichier contenant les méthodes de tests pour la fonction ComputeMeanForAnAttribute

/*

Signature : ComputeMeanForAnAttribute (double latitude, double longitude, string &attribute, double radius, Timestamp startTime, Timestamp endTime)

Description :  Cette fonction calcule la moyenne des valeurs d'un attribut spécifié 
               (O3, NO2, SO2, PM10) pour une zone géographique donnée et sur une période de temps spécifiée.

Remarque :    Les mesures sont stockées dans "vector<Measurement*> vecteurMeasurements du ComputationAgent"

*/

bool Test::CMFAA_case1_MeanForO3(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Moyenne pour O3 : toutes les données sont prises en compte
    */
   cout <<"Cas 1: Moyenne pour O3 : toutes les données sont prises en compte. ";
   
    ComputationAgent *calculateur = new ComputationAgent();

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 20.0; Timestamp timestamp2("2019-01-01 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  O3);
   
   double value3 = 30.0; Timestamp timestamp3("2019-01-02 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  O3);

   double value4 = 40.0; Timestamp timestamp4("2019-01-03 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  O3);
   
   double value5 = 50.0; Timestamp timestamp5("2019-01-04 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor1,  O3);
    calculateur->vecteurMeasurements = {m1, m2, m3, m4, m5};   
   
    Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
    double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime);
    double sortie_attendue = 30.0;
    
    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Reussi!" <<endl;
    } else {
        cout << "Echoue!" <<endl;
        cout << "   Sortie obtenue: " << sortie_obtenue <<endl;
        cout << "   Sortie attendue: " << sortie_attendue <<endl;
    }

    delete calculateur;
    return result ;

}

bool Test::CMFAA_case2_FiltrageDate(){
    /*
       Des données ne sont pas prises en compte à cause de la date

    */
   cout <<"Cas 1: Des données ne sont pas prises en compte à cause de la date. ";
   
    ComputationAgent *calculateur = new ComputationAgent();

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures prises en compte
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 20.0; Timestamp timestamp2("2019-01-01 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  O3);
   
   double value3 = 30.0; Timestamp timestamp3("2019-01-02 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  O3);

   double value4 = 40.0; Timestamp timestamp4("2019-01-03 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  O3);
   
   double value5 = 50.0; Timestamp timestamp5("2019-01-04 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor1,  O3);

   //Création des mesures pas prises en compte
   double value6 = 200.0; Timestamp timestamp6("2018-01-04 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor1,  O3);
   
   double value7 = 350.0; Timestamp timestamp7("2018-01-04 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor1,  O3);

   double value8 = 200.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor1,  O3);
   
   double value9 = 350.0; Timestamp timestamp9("2020-01-04 01:00:00");  
   Measurement* m9 = new Measurement(value9, timestamp9, sensor1,  O3);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9};

    Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
    double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime);
    double sortie_attendue = 30.0;
    
    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Reussi!" <<endl;
    } else {
        cout << "Echoue!" <<endl;
        cout << "   Sortie obtenue: " << sortie_obtenue <<endl;
        cout << "   Sortie attendue: " << sortie_attendue <<endl;
    }

    delete calculateur;
    return result ;

}

bool Test::CMFAA_case3_FiltragePosition(){
    /*
        Des données ne sont pas prises en compte à cause de leur position
    */
    cout <<"Cas 3: Des données ne sont pas prises en compte à cause de leur position. ";
   
    ComputationAgent *calculateur = new ComputationAgent();

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 70.0, 178.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;
    calculateur->hmapIdSensor[2] = sensor2;

   //Création des mesures prises en compte
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 20.0; Timestamp timestamp2("2019-01-01 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  O3);
   
   double value3 = 30.0; Timestamp timestamp3("2019-01-02 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  O3);

   double value4 = 40.0; Timestamp timestamp4("2019-01-03 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  O3);
   
   double value5 = 50.0; Timestamp timestamp5("2019-01-04 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor1,  O3);

   //Création des mesures pas prises en compte car sensor 2 hors de la zone
   double value6 = 200.0; Timestamp timestamp6("2018-01-04 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  O3);
   
   double value7 = 350.0; Timestamp timestamp7("2018-01-04 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  O3);

   double value8 = 200.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor2,  O3);
   
   double value9 = 350.0; Timestamp timestamp9("2020-01-04 01:00:00");  
   Measurement* m9 = new Measurement(value9, timestamp9, sensor2,  O3);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9};

    Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
    double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime);
    double sortie_attendue = 30.0;
    
    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Reussi!" <<endl;
    } else {
        cout << "Echoue!" <<endl;
        cout << "   Sortie obtenue: " << sortie_obtenue <<endl;
        cout << "   Sortie attendue: " << sortie_attendue <<endl;
    }

    delete calculateur;
    return result ;

}

bool Test::CMFAA_case4_FiltrageMoleculeErreurPasMesure(){
    /*
       Des données ne sont pas prises en compte car elles ne sont pas sur la bonne molécule et il n’y a pas de mesure pour la molécule en question
    */

   cout <<"Cas 4: Des données ne sont pas prises en compte car elles ne sont pas sur la bonne molécule et il n’y a pas de mesure pour la molécule en question. ";
   
    ComputationAgent *calculateur = new ComputationAgent();

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures pas prises en compte car pas sur la bonne molécule
   double value6 = 200.0; Timestamp timestamp6("2018-01-04 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor1,  SO2);
   
   double value7 = 350.0; Timestamp timestamp7("2018-01-04 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor1,  NO2);

   double value8 = 200.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor1,  NO2);
   
   double value9 = 350.0; Timestamp timestamp9("2020-01-04 01:00:00");  
   Measurement* m9 = new Measurement(value9, timestamp9, sensor1,  PM10);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m6, m7, m8, m9};

    Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
    double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime);
    double sortie_attendue = -1.0;
    
    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Reussi!" <<endl;
    } else {
        cout << "Echoue!" <<endl;
        cout << "   Sortie obtenue: " << sortie_obtenue <<endl;
        cout << "   Sortie attendue: " << sortie_attendue <<endl;
    }

    delete calculateur;
    return result ;
}

bool Test::CMFAA_case5_RayonIncorrect(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Rayon < 0 
    */
   cout <<"Cas 1: Entrée invalide : Rayon < 0. ";
   
    ComputationAgent *calculateur = new ComputationAgent();


   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1};   

    try
    {
        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(45.0, 1.0, "O3", -1.0, startTime, endTime);
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        delete calculateur;
        if ( msg != "Le rayon doit être positif!") {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << "Le rayon doit être positif!" << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }

}

bool Test::CMFAA_case6_LatitudeIncorrecte(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Latitude > 90°
    */
   cout <<"Cas 6: Entrée invalide : Latitude > 90°. ";
    ComputationAgent *calculateur = new ComputationAgent();


   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1};   

    try
    {
        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(180.0, 1.0, "O3", 1.0, startTime, endTime);
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        string expected_msg = "La latitude doit être comprise entre -90° et 90°";
        delete calculateur;
        if ( msg != expected_msg) {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << expected_msg << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }
}

bool Test::CMFAA_case7_LongitudeIncorrecte(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Longitude > 180°
    */

    cout <<"Cas 7: Entrée invalide : Longitude > 180°. ";
    ComputationAgent *calculateur = new ComputationAgent();


   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1};   

    try
    {
        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(50.0, 200.0, "O3", 1.0, startTime, endTime);
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        string expected_msg = "La longitude doit être comprise entre -180° et 180°";
        delete calculateur;
        if ( msg != expected_msg) {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << expected_msg << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }

}

bool Test::CMFAA_case8_DatesIncorrectes(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : DateFin < DateDebut

    */
    cout <<"Cas 8: Entrée invalide : DateFin < DateDebut. ";
    ComputationAgent *calculateur = new ComputationAgent();


   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
    calculateur->hmapAttributes["O3"] = O3;
    calculateur->hmapAttributes["SO2"] = SO2;
    calculateur->hmapAttributes["NO2"] = NO2;
    calculateur->hmapAttributes["PM10"] = PM10;

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
    calculateur->hmapIdSensor[1] = sensor1;

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    calculateur->vecteurMeasurements = {m1};   

    try
    {
        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        double sortie_obtenue = calculateur->ComputeMeanForAnAttribute(50.0, 10.0, "O3", 1.0, endTime, startTime); 
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        string expected_msg = "La date de fin doit être > à la date du début";
        delete calculateur;
        if ( msg != expected_msg) {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << expected_msg << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }

}



bool Test::CMFAA_case9_MesureInvalide(){
    /*
        Retourne true si le test a fonctionné et false sinon
        Il y a au moins une valeur de mesure  invalide car < 0 pour la molécule spécifiée
    */
    cout <<"Cas 9: Il y a au moins une valeur de mesure invalide car < 0 donc ERREUR. ";
    ComputationAgent *calculateur = new ComputationAgent();

    try {
        //Création des Attributs 
        Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
        Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
        Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
        Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
        calculateur->hmapAttributes["O3"] = O3;
        calculateur->hmapAttributes["SO2"] = SO2;
        calculateur->hmapAttributes["NO2"] = NO2;
        calculateur->hmapAttributes["PM10"] = PM10;

        //Création des capteurs
        Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
        calculateur->hmapIdSensor[1] = sensor1;

        //Création des mesures
        double value1 = -10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
        Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
        
        // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
       calculateur->vecteurMeasurements = {m1};  

        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        int sortie_obtenue = calculateur->ComputeMeanForAnAttribute(50.0, 10.0, "O3", 1.0, startTime, endTime); 
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false; 
    }
    catch(const exception& e)
    {
        string msg(e.what());
        string expected_msg = "La valeur de mesure doit etre >= 0!";
        delete calculateur;
        if ( msg != expected_msg) {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << expected_msg << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }

}

bool Test::CMFAA_case10_MoleculeExistePas(){
    /*
        Entrée invalide : La molécule n'existe pas
    */

    cout <<"Cas 10: Entrée invalide : La molécule n'existe pas. ";
    ComputationAgent *calculateur = new ComputationAgent();

    try {
        //Création des Attributs 
        Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
        Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
        Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
        Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");
        calculateur->hmapAttributes["O3"] = O3;
        calculateur->hmapAttributes["SO2"] = SO2;
        calculateur->hmapAttributes["NO2"] = NO2;
        calculateur->hmapAttributes["PM10"] = PM10;

        //Création des capteurs
        Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
        calculateur->hmapIdSensor[1] = sensor1;

        //Création des mesures
        double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
        Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
        
        // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
       calculateur->vecteurMeasurements = {m1};  

        Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
        int sortie_obtenue = calculateur->ComputeMeanForAnAttribute(50.0, 10.0, "LOL", 1.0, startTime, endTime); 
        
        delete calculateur;
        cout << "Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false; 
    }
    catch(const exception& e)
    {
        string msg(e.what());
        string expected_msg = "La molécule n'existe pas!";
        delete calculateur;
        if ( msg != expected_msg) {
            cout << "Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << expected_msg << endl;
            return false;
        } else {
            cout << "Reussi!" << endl;
            return true;
        }
    }

}