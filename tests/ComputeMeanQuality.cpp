#include "Test.h"


// Fichier contenant les méthodes de tests pour la fonction ComputeMeanQuality

/*

Signature : ComputeMeanQuality(double latitude, double longitude, double radius, Timestamp startTime, Timestamp endTime)

Description :  Calcule la moyenne de la qualité de l'air dans une zone circulaire (définie par son centre et un rayon) 
               pour un moment donné (DateDebutPourMoyenne = DateFinPourMoyenne)  
               ainsi que pour une période de temps spécifiée   

*/

bool Test::CMQ_case1_testDeBase(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Toutes les données sont prises en compte et il y a 2 données par molécule
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 10.0; Timestamp timestamp2("2019-01-02 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  SO2);
   
   double value3 = 10.0; Timestamp timestamp3("2019-01-03 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  NO2);

   double value4 = 10.0; Timestamp timestamp4("2019-01-04 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  PM10);

   
   double value5 = 20.0; Timestamp timestamp5("2019-01-01 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor2,  O3);

   double value6 = 30.0; Timestamp timestamp6("2018-01-02 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  SO2);
   
   double value7 = 40.0; Timestamp timestamp7("2018-01-03 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  NO2);

   double value8 = 50.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor2,  PM10);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, 1.0, startTime, endTime)
   //return atmo==5;

}

bool Test::CMQ_case2_filtrageDate(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Des données ne sont pas prises en compte à cause de la date et il y a 2 données par AttributeID (molécule)
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 45.0, 1.0, nullptr);

   //Création des mesures prises en compte
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 10.0; Timestamp timestamp2("2019-01-02 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  SO2);
   
   double value3 = 10.0; Timestamp timestamp3("2019-01-03 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  NO2);

   double value4 = 10.0; Timestamp timestamp4("2019-01-04 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  PM10);

   
   double value5 = 20.0; Timestamp timestamp5("2019-01-01 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor2,  O3);

   double value6 = 30.0; Timestamp timestamp6("2018-01-02 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  SO2);
   
   double value7 = 40.0; Timestamp timestamp7("2018-01-03 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  NO2);

   double value8 = 50.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor2,  PM10);

   //Création des mesures pas prises en compte (à cause de la date !!!)
   double value9 = 1000.0; Timestamp timestamp9("2019-03-03 01:00:00");  
   Measurement* m9 = new Measurement(value9, timestamp9, sensor1,  O3);

   double value10 = 1000.0; Timestamp timestamp10("2019-03-04 01:00:00");  
   Measurement* m10 = new Measurement(value10, timestamp10, sensor1,  SO2);

   double value11 = 1000.0; Timestamp timestamp11("2019-03-05 01:00:00");  
   Measurement* m11 = new Measurement(value11, timestamp11, sensor1,  NO2);

   double value12 = 1000.0; Timestamp timestamp12("2019-03-06 01:00:00");  
   Measurement* m12 = new Measurement(value12, timestamp12, sensor1,  PM10);


   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, 1.0, startTime, endTime)
   //return atmo==5;

}

bool Test::CMQ_case3_filtragePosition(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
       Des données ne sont pas prises en compte à cause de leur position et il y a 2 données par AttributeID (molécule)
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 45.0, 1.0, nullptr);
   Sensor* sensor3 = new Sensor(3, 30.0, -158.0, nullptr);

   //Création des mesures prises en compte
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 10.0; Timestamp timestamp2("2019-01-02 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  SO2);
   
   double value3 = 10.0; Timestamp timestamp3("2019-01-03 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  NO2);

   double value4 = 10.0; Timestamp timestamp4("2019-01-04 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  PM10);

   
   double value5 = 20.0; Timestamp timestamp5("2019-01-01 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor2,  O3);

   double value6 = 30.0; Timestamp timestamp6("2018-01-02 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  SO2);
   
   double value7 = 40.0; Timestamp timestamp7("2018-01-03 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  NO2);

   double value8 = 50.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor2,  PM10);

   //Création des mesures pas prises en compte (à cause de la date !!!)
   double value9 = 1000.0; Timestamp timestamp9("2020-01-04 01:00:00"); 
   Measurement* m9 = new Measurement(value9, timestamp9, sensor3,  O3);

   double value10 = 1000.0; Timestamp timestamp10("2020-01-04 01:00:00"); 
   Measurement* m10 = new Measurement(value10, timestamp10, sensor3,  SO2);

   double value11 = 1000.0; Timestamp timestamp11("2020-01-04 01:00:00"); 
   Measurement* m11 = new Measurement(value11, timestamp11, sensor3,  NO2);

   double value12 = 1000.0; Timestamp timestamp12("2020-01-04 01:00:00");
   Measurement* m12 = new Measurement(value12, timestamp12, sensor3,  PM10);


   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, 1.0, startTime, endTime)
   //return atmo==5;

}

bool Test::CMQ_case4_manqueUneMolecule(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Pour une des molécules (PM10) il n’y a pas de mesure donc renvoie -1
    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = 10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 10.0; Timestamp timestamp2("2019-01-02 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  SO2);
   
   double value3 = 10.0; Timestamp timestamp3("2019-01-03 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  NO2);

   
   double value5 = 20.0; Timestamp timestamp5("2019-01-01 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor2,  O3);

   double value6 = 30.0; Timestamp timestamp6("2018-01-02 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  SO2);
   
   double value7 = 40.0; Timestamp timestamp7("2018-01-03 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  NO2);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m5, m6, m7};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, 1.0, startTime, endTime)
   //return atmo==-1; // Erreur car il manque des données pour une molécule !

}

bool Test::CMQ_case5_rayonInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Rayon Invalide (rayon<0)
    */

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, -1.0, startTime, endTime)
   //return atmo==-1; // Erreur car rayon<0

}

bool Test::CMQ_case6_latitudeInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Latitude > 90°
    */

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(95.0, 1.0, 1.0, startTime, endTime) // Erreur car latitude>90
   //return atmo==-1; // Erreur car latitude>90

}

bool Test::CMQ_case7_longitudeInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : Longitude > 180°

    */

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(89.0, 182.0, 1.0, startTime, endTime) // Erreur car Longitude > 180°
   //return atmo==-1; // Erreur car Longitude > 180°

}

bool Test::CMQ_case8_DatesInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Entrée invalide : DateFin < DateDebut
    */

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(89.0, 10.0, 1.0, endTime, startTime) // Erreur car DateFin < DateDebut
   //return atmo==-1; // Erreur car DateFin < DateDebut

}

bool Test::CMQ_case9_MesureInvalide(ComputationAgent c){
    /*
        Retourne true si le test a fonctionné et false sinon
        Il y a au moins une valeur de mesure invalide car < 0 donc ERREUR

    */

   //Création des Attributs 
   Attributes* O3 = new Attributes("O3", "µg/m3", "concentration d'ozone");
   Attributes* SO2 = new Attributes("SO2", "µg/m3", "concentration de dioxyde de soufre");
   Attributes* NO2 = new Attributes("NO2", "µg/m3", "concentration de dioxyde d'azote");
   Attributes* PM10 = new Attributes("PM10", "µg/m3", "concentration de particules fines");

   //Création des capteurs
   Sensor* sensor1 = new Sensor(1, 45.0, 1.0, nullptr);
   Sensor* sensor2 = new Sensor(2, 45.0, 1.0, nullptr);

   //Création des mesures
   double value1 = -10.0; Timestamp timestamp1("2019-01-01 01:00:00"); 
   Measurement* m1 = new Measurement(value1, timestamp1, sensor1,  O3);
   
   double value2 = 10.0; Timestamp timestamp2("2019-01-02 01:00:00");  
   Measurement* m2 = new Measurement(value2, timestamp2, sensor1,  SO2);
   
   double value3 = 10.0; Timestamp timestamp3("2019-01-03 01:00:00");  
   Measurement* m3 = new Measurement(value3, timestamp3, sensor1,  NO2);

   double value4 = 10.0; Timestamp timestamp4("2019-01-04 01:00:00");  
   Measurement* m4 = new Measurement(value4, timestamp4, sensor1,  PM10);

   
   double value5 = 20.0; Timestamp timestamp5("2019-01-01 01:00:00");  
   Measurement* m5 = new Measurement(value5, timestamp5, sensor2,  O3);

   double value6 = 30.0; Timestamp timestamp6("2018-01-02 01:00:00");  
   Measurement* m6 = new Measurement(value6, timestamp6, sensor2,  SO2);
   
   double value7 = 40.0; Timestamp timestamp7("2018-01-03 01:00:00");  
   Measurement* m7 = new Measurement(value7, timestamp7, sensor2,  NO2);

   double value8 = 50.0; Timestamp timestamp8("2020-01-04 01:00:00");  
   Measurement* m8 = new Measurement(value8, timestamp8, sensor2,  PM10);

   // On ajoute à la structure contenant les mesures et on set l'attribute du paramètre
    vector<Measurement*> vecteurMeasurements = {m1, m2, m3, m4, m5, m6, m7, m8};   

   // --> A decommenter quand ils auront fait les setters des structures de données et mis les méthodes protected en public sinon pas de unittest!!
   //c.set;
   //Timestamp startTime("2019-01-01 01:00:00");  Timestamp endTime("2019-02-01 01:00:00"); 
   //int atmo = c.ComputeMeanQuality(45.0, 1.0, 1.0, startTime, endTime)
   //return atmo==-1; // Erreur car une valeur < 0

}





