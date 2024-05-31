//---------- Réalisation de la classe <Results> (fichier Results.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Results.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void Results::GreetingsUser(User user) 
{
    string email = user.getEmail();
    string prenom = email.substr(0, email.find('.'));
    cout << "Bonjour " << prenom << " !" << endl;
}

string Results::GetUserInput() {
    string input;
    cout << "Que souhaitez-vous faire ?" << endl;
    cin >> input;
    return input;
} 

Results::Results ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Results>" << endl;
#endif

}

Results::~Results ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Results>" << endl;
#endif
}

