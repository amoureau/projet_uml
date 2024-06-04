#include "Test.h"


// Fichier contenant les méthodes de tests pour la fonction ComputeMeanForAnAttribute

/*

Signature : ComputeMeanForAnAttribute (double latitude, double longitude, string &attribute, double radius, Timestamp startTime, Timestamp endTime)

Description :  Cette fonction calcule la moyenne des valeurs d'un attribut spécifié 
               (O3, NO2, SO2, PM10) pour une zone géographique donnée et sur une période de temps spécifiée.

Remarque :    Les mesures sont stockées dans "vector<Measurement*> vecteurMeasurements du ComputationAgent"

*/

bool Test::CMFAA_case1_MeanForO3(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Moyenne pour O3 : toutes les données sont prises en compte
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

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

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime);
   //return Moyenne==30.0;

}

bool Test::CMFAA_case2_FiltrageDate(ComputationAgent c){
    /*
       Des données ne sont pas prises en compte à cause de la date

    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

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
   vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9};
   
   /* --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   c.set...
   Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   double Moyenne = c.ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime)
   return Moyenne==30.0;
   */

}

bool Test::CMFAA_case3_FiltragePosition(ComputationAgent c){
    /*
        Des données ne sont pas prises en compte à cause de leur position
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 70.0, 178.0, nullptr);

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
   vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9};
   
   /* --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   c.set...
   Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   double Moyenne = c.ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime)
   return Moyenne==30.0;
   */

}

bool Test::CMFAA_case4_FiltrageMoleculeErreurPasMesure(ComputationAgent c){
    /*
       Des données ne sont pas prises en compte car elles ne sont pas sur la bonne molécule et il n’y a pas de mesure pour la molécule en question
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

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
   vector<Measurement*> vecteurMeasurements = {m6, m7, m8, m9};
   
   /* --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   c.set...
   Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   double Moyenne = c.ComputeMeanForAnAttribute(45.0, 1.0, "O3", 1.0, startTime, endTime)
   return Moyenne == -1.0; // Cas Erreur
   */

}

bool Test::CMFAA_case5_RayonIncorrect(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Rayon < 0 
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(45.0, 1.0, "O3", -1.0, startTime, endTime); // Erreur car rayon negatif
   //return Moyenne == -1.0; // Erreur car rayon negatif

}

bool Test::CMFAA_case6_LatitudeIncorrecte(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Latitude > 90°
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(180.0, 1.0, "O3", 1.0, startTime, endTime); // Erreur car Latitude > 90°
   //return Moyenne == -1.0; // Erreur car Latitude > 90°

}

bool Test::CMFAA_case7_LongitudeIncorrecte(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Longitude > 180°
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(50.0, 200.0, "O3", 1.0, startTime, endTime); // Erreur car Longitude > 180°
   //return Moyenne == -1.0; // Erreur car Longitude > 180°

}

bool Test::CMFAA_case8_DatesIncorrectes(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : DateFin < DateDebut

    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(50.0, 10.0, "O3", 1.0, endTime, startTime); // Erreur car DateFin < DateDebut
   //return Moyenne == -1.0; // Erreur car DateFin < DateDebut

}



bool Test::CMFAA_case9_MesureInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Il y a au moins une valeur de mesure  invalide car < 0 pour la molécule spécifiée
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = -10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(50.0, 10.0, "O3", 1.0, startTime, endTime); 
   //return Moyenne == -1.0; // Erreur car une mesure invalide

}

bool Test::CMFAA_case10_MoleculeExistePas(ComputationAgent c){
    /*
        Entrée invalide : La molécule n'existe pas
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //double Moyenne = c.ComputeMeanForAnAttribute(50.0, 10.0, "LOL", 1.0, startTime, endTime); // Erreur car moleculeExistePas
   //return Moyenne == -1.0; // Erreur car moleculeExistePas

}