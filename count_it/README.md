# Count It!

## Description

Ce projet contient une fonction récursive qui interroge l'API Reddit pour analyser les titres des articles populaires d'un subreddit donné et affiche un décompte trié des mots-clés spécifiés.

## Prérequis

- Ubuntu 14.04 LTS
- Python 3.4.3
- Respect du style PEP 8
- Module Requests pour les requêtes HTTP

## Tâche

### 0. Count it!

Écrire une fonction récursive qui interroge l'API Reddit, analyse les titres de tous les articles populaires et affiche un décompte trié des mots-clés donnés (insensible à la casse, délimités par des espaces).

**Prototype:** `def count_words(subreddit, word_list)`

**Fonctionnalités:**
- Correspondance des mots-clés insensible à la casse
- Gestion récursive de la pagination de l'API
- Les mots avec ponctuation (ex: `java.`, `java!`, `java_`) ne sont pas comptés comme des correspondances
- Les mots-clés en double dans `word_list` sont additionnés dans le décompte final
- Résultats affichés par ordre décroissant du nombre d'occurrences
- En cas d'égalité, tri alphabétique (A-Z)
- Les mots sans correspondance sont ignorés
- Les subreddits invalides n'affichent rien
- Ne suit pas les redirections

## Utilisation

```bash
python3 0-main.py <subreddit> '<mot-clé1> <mot-clé2> ...'
```

### Exemples

```bash
$ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4

$ python3 0-main.py programming 'JavA java'
java: 54

$ python3 0-main.py not_a_valid_subreddit 'python java'
$
```

## Fichiers

- `0-count.py`: Fichier d'implémentation principal contenant la fonction `count_words()`
- `0-main.py`: Fichier de test pour exécuter la fonction

## Auteur

Projet d'interview Holberton School
