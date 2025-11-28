# Linear Skip - Recherche dans une Skip List

## Description

Ce projet implémente un algorithme de recherche optimisé dans une **skip list** (liste chaînée avec voie express). Une skip list est une structure de données qui améliore les performances de recherche dans une liste chaînée en ajoutant une "voie express" permettant de sauter plusieurs éléments à la fois.

## Concept

Une skip list possède deux niveaux de pointeurs :
- **next** : pointe vers l'élément suivant (liste normale)
- **express** : pointe vers un élément plus loin dans la liste (voie express)

Dans ce projet, un nœud de la voie express est placé à chaque indice qui est un multiple de la racine carrée de la taille de la liste.

### Exemple avec 16 éléments (√16 = 4)
```
Liste normale : 0 → 1 → 2 → 3 → 4 → 7 → 12 → 15 → 18 → 19 → 23 → 53 → 61 → 62 → 76 → 99
Voie express  : 0 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 4 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 8 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 12
```

## Algorithme

L'algorithme `linear_skip` fonctionne en deux étapes :

1. **Parcours de la voie express** : Sauter rapidement à travers la liste en utilisant les pointeurs `express` jusqu'à trouver un nœud dont la valeur est supérieure ou égale à la valeur recherchée.

2. **Recherche linéaire** : Une fois la plage identifiée, effectuer une recherche linéaire classique entre le nœud précédent et le nœud actuel de la voie express.

## Structure de données

```c
typedef struct skiplist_s
{
    int n;                      /* Valeur stockée */
    size_t index;               /* Index dans la liste */
    struct skiplist_s *next;    /* Pointeur vers le prochain nœud */
    struct skiplist_s *express; /* Pointeur vers le prochain nœud express */
} skiplist_t;
```

## Fichiers

- **search.h** : Fichier d'en-tête contenant la structure et les prototypes
- **0-linear_skip.c** : Implémentation de la fonction de recherche
- **0-main.c** : Fichier de test principal
- **create_skiplist.c** : Fonction auxiliaire pour créer une skip list
- **print_skiplist.c** : Fonction auxiliaire pour afficher une skip list
- **free_skiplist.c** : Fonction auxiliaire pour libérer la mémoire

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c create_skiplist.c print_skiplist.c free_skiplist.c -lm -o 0-linear_skip
```

## Utilisation

```bash
./0-linear_skip
```

## Exemple de sortie

```
List :
Index[0] = [0]
Index[1] = [1]
...
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## Complexité

- **Meilleur cas** : O(1) - la valeur est au premier nœud
- **Cas moyen** : O(√n) - grâce à la voie express
- **Pire cas** : O(n) - la valeur est à la fin ou n'existe pas

Sans la voie express, une liste chaînée classique aurait une complexité de O(n) dans tous les cas.

## Auteur

Projet Holberton School - Interview Preparation

## Exigences

- Éditeurs autorisés : `vi`, `vim`, `emacs`
- Compilation sur Ubuntu 14.04 LTS
- Compilateur : `gcc 4.8.4`
- Flags de compilation : `-Wall -Werror -Wextra -pedantic`
- Style de code : Betty
- Maximum 5 fonctions par fichier
- Tous les fichiers doivent se terminer par une nouvelle ligne
- Tous les fichiers d'en-tête doivent avoir des gardes d'inclusion
