# API Star Wars

## Description

Ce projet contient un script qui affiche tous les personnages d'un film Star Wars en utilisant l'API Star Wars (SWAPI).

## Prérequis

- Node.js version 10.14.x ou supérieure
- Module npm `request`
- Éditeurs autorisés : vi, vim, emacs
- Système : Ubuntu 14.04 LTS

## Installation

### Installer Node 10

```bash
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
sudo apt-get install -y nodejs
```

### Installer semi-standard

```bash
sudo npm install semistandard --global
```

### Installer le module request

```bash
sudo npm install request --global
export NODE_PATH=/usr/lib/node_modules
```

Ou localement dans le projet :

```bash
npm install request
```

## Exigences

- Tous les fichiers doivent se terminer par une nouvelle ligne
- La première ligne de tous les fichiers doit être exactement `#!/usr/bin/node`
- Le code doit être conforme à semistandard (Standard + points-virgules)
- Tous les fichiers doivent être exécutables
- L'utilisation de `var` n'est pas autorisée

## Utilisation

### Tâche 0 : Personnages Star Wars

Le script affiche tous les personnages d'un film Star Wars :

```bash
./0-starwars_characters.js <movie_id>
```

**Arguments :**
- `movie_id` : L'identifiant du film (par exemple : 3 = "Le Retour du Jedi")

**Exemple :**

```bash
./0-starwars_characters.js 3
```

**Sortie attendue :**

```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Fonctionnement

Le script :
1. Récupère l'identifiant du film passé en premier argument
2. Fait une requête à l'endpoint `/films/` de l'API Star Wars
3. Extrait la liste des URLs des personnages
4. Récupère les informations de chaque personnage dans l'ordre
5. Affiche un nom de personnage par ligne

## API utilisée

- **API Star Wars** : https://swapi-api.hbtn.io/api/
- **Documentation** : https://swapi-api.hbtn.io/documentation

## Identifiants des films

- 1 : Un nouvel espoir (A New Hope)
- 2 : L'Empire contre-attaque (The Empire Strikes Back)
- 3 : Le Retour du Jedi (Return of the Jedi)
- 4 : La Menace fantôme (The Phantom Menace)
- 5 : L'Attaque des clones (Attack of the Clones)
- 6 : La Revanche des Sith (Revenge of the Sith)

## Fichiers

- `0-starwars_characters.js` : Script principal qui affiche les personnages d'un film

## Auteur

Projet réalisé dans le cadre du cursus Holberton School

## Dépôt

- **GitHub repository** : holbertonschool-interview
- **Directory** : starwars_api
- **File** : 0-starwars_characters.js
