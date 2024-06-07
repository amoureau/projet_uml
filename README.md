# README

## Projet : Analyse de la qualité de l'air

### Description
Ce projet est une application C++ permettant d'analyser la qualité de l'air à partir de diverses données collectées par des capteurs. L'application permet aux utilisateurs de différents rôles (administrateurs, gouvernement, individus privés, fournisseurs) d'interagir avec le système pour obtenir des informations sur la qualité de l'air dans des zones spécifiques ou de vérifier les anomalies des capteurs.

### Structure du projet

Le projet suit une architecture MVC:

- **Controller.h / Controller.cpp** : Gère les interactions avec l'utilisateur et orchestre les différentes fonctionnalités de l'application.
- **ComputationAgent** : Effectue les calculs nécessaires pour analyser les données de qualité de l'air.
- **User, Admin, Government, PrivateIndividual, Provider** : Représentent les différents types d'utilisateurs du système.
- **Results** : Gère l'affichage des résultats pour l'utilisateur.
- **Test** : Contient les tests pour vérifier le bon fonctionnement des différentes fonctionnalités du système.

### Fonctionnalités principales

1. **Affichage des données**
   - Affichage des capteurs, individus privés, attributs, nettoyeurs, fournisseurs, descriptions des attributs, mesures et coordonnées des capteurs.
   
2. **Analyse de la qualité de l'air**
   - Analyser la qualité de l'air dans une zone spécifique sur une période de temps définie.
   
3. **Analyse des capteurs**
   - Vérifier les anomalies des capteurs dans une zone spécifique.

### Exécution du programme

#### Prérequis

- Compilateur C++ (compatible C++11 ou supérieur)
- Système d'exploitation compatible avec les compilateurs C++ standards

#### Compilation

Pour compiler le projet, utilisez une commande comme celle-ci dans le terminal :

```bash
make
```
Pour nettoyer les fichiers compilés utilisez la commande make suivante:

```bash
make clean
```

#### Exécution

Pour exécuter le programme, utilisez la commande suivante :

```bash
./airwatcher
```

Pour exécuter les tests, utilisez la commande suivante :

```bash
./airwatcher test
```

### Utilisation

Lors de l'exécution, le programme vous guidera à travers diverses options pour analyser la qualité de l'air ou vérifier les anomalies des capteurs. Les utilisateurs peuvent choisir leur rôle et les actions qu'ils souhaitent effectuer en suivant les instructions affichées.

### Extrait du code `main`

```cpp
#include "Controller.h"
#include "../tests/Test.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "test" || mode == "Test") {
            Test *test = new Test();
            test->testAll();
            delete test;
            return 0;
        }
    }

    Controller *controller = new Controller();
    controller->mainController();
    delete controller;
    return 0;
}
```

### Licence

Ce projet est sous licence MIT. Veuillez consulter le fichier LICENSE pour plus de détails.

### Auteurs

- **SAMAIN** - *Développeur data* - [VotreProfilGitHub](https://github.com/Shaunerie)
- **MOUREAU** - (https://github.com/amoureau)
- **NGO**
- **LEVRARD**

---

N'hésitez pas à contacter l'auteur pour toute question ou suggestion concernant ce projet.