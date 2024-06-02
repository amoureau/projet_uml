#include "Test.h"

// Fichier contenant les méthodes de tests pour la fonction ComputeMeanForAnAttribute

bool Test::CD_cas1_entree_valide() {
    double lat1 = 1;
    double lng1 = 1;
    double lat2 = 2;
    double lng2 = 2;

    double sortie_attendue = 157.5;
    double sortie_obtenue = ComputationAgent::calculateDistance(lat1, lng1, lat2, lng2);

    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Cas 1: entree validee. Reussi!" << endl;
    } else {
        cout << "Cas 1: entree validee. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

bool Test::CD_cas2_entree_valide() {
    double lat1 = 67;
    double lng1 = 174;
    double lat2 = 26;
    double lng2 = 32;

    double sortie_attendue = 9198.0;
    double sortie_obtenue = ComputationAgent::calculateDistance(lat1, lng1, lat2, lng2);

    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Cas 2: entree validee. Reussi!" << endl;
    } else {
        cout << "Cas 2: entree validee. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

bool Test::CD_cas3_entree_valide_2_points_egaux() {
    double lat1 = 1;
    double lng1 = 1;
    double lat2 = 1;
    double lng2 = 1;

    double sortie_attendue = 0.0;
    double sortie_obtenue = ComputationAgent::calculateDistance(lat1, lng1, lat2, lng2);

    bool result = isEgalDouble(sortie_attendue, sortie_obtenue);
    if (result) {
        cout << "Cas 3: entree validee - 2 points egaux. Reussi!" << endl;
    } else {
        cout << "Cas 3: entree validee. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << sortie_attendue << endl;
    }
    return result ;
}

bool Test::CD_cas4_entree_lat_invalide() {
    try
    {
        double lat1 = 91;
        double lng1 = 1;
        double lat2 = 1;
        double lng2 = 1;

        double sortie_obtenue = ComputationAgent::calculateDistance(lat1, lng1, lat2, lng2);

        cout << "Cas 4: entree latitude invalide. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        if (msg != "La latitude doit être comprise entre -90° et 90°") {
            cout << "Cas 4: entree latitude invalide. Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << "La latitude doit être comprise entre -90° et 90°" << endl;
            return false;
        } else {
            cout << "Cas 4: entree latitude invalide. Reussi!" << endl;
            return true;
        }
    }
}

bool Test::CD_cas5_entree_lng_invalide() {
    try
    {
        double lat1 = 1;
        double lng1 = 1;
        double lat2 = 1;
        double lng2 = 181;

        double sortie_obtenue = ComputationAgent::calculateDistance(lat1, lng1, lat2, lng2);

        cout << "Cas 5: entree latitude invalide. Echoue!" << endl;
        cout << "   Sortie obtenue: " << sortie_obtenue << endl;
        cout << "   Sortie attendue: " << "Exception expected" << endl;
        return false;
    }
    catch(const exception& e)
    {
        string msg(e.what());
        if ( msg != "La longitude doit être comprise entre -180° et 180°") {
            cout << "Cas 5: entree latitude invalide. Echoue!" << endl;
            cout << "   Exception obtenue: " << msg << endl;
            cout << "   Exception attendue: " << "La longitude doit être comprise entre -180° et 180°" << endl;
            return false;
        } else {
            cout << "Cas 5: entree latitude invalide. Reussi!" << endl;
            return true;
        }
    }
}