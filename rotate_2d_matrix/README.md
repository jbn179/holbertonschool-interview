# Rotation d'une matrice 2D

## Description

Ce projet implémente une fonction qui effectue une rotation de 90 degrés dans le sens horaire d'une matrice 2D de taille n x n, directement en place (sans créer de nouvelle matrice).

## Prototype

```python
def rotate_2d_matrix(matrix):
```

- La matrice est modifiée en place, la fonction ne retourne rien.
- La matrice sera toujours à 2 dimensions et ne sera jamais vide.

## Exemple

```python
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

rotate_2d_matrix(matrix)
print(matrix)
# [[7, 4, 1],
#  [8, 5, 2],
#  [9, 6, 3]]
```

## Fichiers

- `0-rotate_2d_matrix.py` : Contient la fonction `rotate_2d_matrix`.

## Environnement

- Ubuntu 14.04 LTS
- Python 3.4.3
- Style PEP 8 (version 1.7.x)
- Aucun module importé
