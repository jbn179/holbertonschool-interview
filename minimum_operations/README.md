# 🔢 Minimum Operations

## 📋 Description

Ce projet implémente un algorithme pour résoudre le problème des **Opérations Minimales**. Il s'agit d'un problème classique de programmation dynamique qui utilise la factorisation en nombres premiers pour optimiser les opérations.

## 🎯 Énoncé du Problème

Dans un fichier texte, il y a un seul caractère 'H'. Votre éditeur de texte peut exécuter seulement deux opérations dans ce fichier : **Copy All** et **Paste**. Étant donné un nombre `n`, écrivez une méthode qui calcule le nombre minimum d'opérations nécessaires pour obtenir exactement `n` caractères 'H' dans le fichier.

### Exigences
- **Prototype** : `def minOperations(n)`
- Retourne un entier
- Si `n` est impossible à atteindre, retourne 0
- Seules deux opérations sont autorisées :
  - **Copy All** : copie tout le contenu du fichier
  - **Paste** : colle le contenu précédemment copié

### Exemple
```
n = 9

H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Nombre d'opérations : 6
```

## 🧠 Logique de l'Algorithme

### Insight Clé : Factorisation en Nombres Premiers

Le problème est essentiellement un **problème de factorisation**. Pour obtenir `n` caractères de manière optimale, nous devons trouver la factorisation en nombres premiers de `n`.

**Pourquoi ?**
- Chaque facteur premier représente une séquence "Copy All + (facteur-1) × Paste"
- Pour multiplier par un facteur `k`, nous avons besoin de `k` opérations total :
  - 1 × Copy All
  - (k-1) × Paste

### Exemples d'Analyse

**n = 9** :
- 9 = 3 × 3
- Opérations : 3 + 3 = 6
- Séquence : H → HHH (3 ops) → HHHHHHHHH (3 ops)

**n = 12** :
- 12 = 2 × 2 × 3 = 4 × 3
- Opérations : 2 + 2 + 3 = 7
- Séquence : H → HH (2 ops) → HHHH (2 ops) → HHHHHHHHHHHH (3 ops)

**n = 4** :
- 4 = 2 × 2
- Opérations : 2 + 2 = 4
- Séquence : H → HH (2 ops) → HHHH (2 ops)

## 🔧 Implémentation de l'Algorithme

```python
def minOperations(n):
    """
    Calcule le nombre minimum d'opérations pour obtenir n caractères 'H'.
    
    Args:
        n: Le nombre cible de caractères 'H'
        
    Returns:
        Entier représentant le nombre minimum d'opérations, ou 0 si impossible
    """
    if n <= 1:
        return 0
    
    operations = 0
    factor = 2
    
    # Factorisation en nombres premiers
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
    
    # Si n > 1, c'est un facteur premier restant
    if n > 1:
        operations += n
        
    return operations
```

### Étapes de l'Algorithme

1. **Cas de Base** : Si `n ≤ 1`, retourne 0 (impossible ou inutile)

2. **Factorisation** : 
   - Commence avec le facteur 2
   - Pour chaque facteur qui divise `n` :
     - Ajoute le facteur aux opérations totales
     - Divise `n` par ce facteur
   - Continue jusqu'à `facteur² > n`

3. **Facteur Premier Restant** :
   - Si après factorisation `n > 1`, c'est un nombre premier
   - Ajoute ce facteur premier aux opérations

## 📊 Analyse de Performance

### Complexité Temporelle
- **O(√n)** : Nous testons les facteurs jusqu'à √n
- **Optimisé** : Chaque facteur est traité une seule fois

### Complexité Spatiale
- **O(1)** : Utilise seulement quelques variables
- **Pas de récursion** : Algorithme itératif

### Cas d'Analyse

| **n** | **Factorisation** | **Opérations** | **Séquence Optimale** |
|-------|-------------------|----------------|----------------------|
| 4 | 2 × 2 | 4 | H→HH→HHHH |
| 6 | 2 × 3 | 5 | H→HH→HHHHHH |
| 8 | 2³ | 6 | H→HH→HHHH→HHHHHHHH |
| 9 | 3² | 6 | H→HHH→HHHHHHHHH |
| 12 | 2² × 3 | 7 | H→HH→HHHH→HHHHHHHHHHHH |
| 15 | 3 × 5 | 8 | H→HHH→HHHHHHHHHHHHHHH |

## 🧪 Tests et Validation

### Structure des Fichiers
```
minimum_operations/
├── 0-minoperations.py    # Implémentation principale
├── 0-main.py            # Tests fournis
└── README.md            # Cette documentation
```

### Exécution des Tests
```bash
./0-main.py
```

### Résultats Attendus
```
Min # of operations to reach 4 char: 4
Min # of operations to reach 12 char: 7
```

### Tests Supplémentaires
```python
# Test cases supplémentaires pour validation
test_cases = [
    (1, 0),    # Cas impossible
    (2, 2),    # Nombre premier
    (3, 3),    # Nombre premier
    (4, 4),    # 2²
    (5, 5),    # Nombre premier
    (6, 5),    # 2 × 3
    (8, 6),    # 2³
    (9, 6),    # 3²
    (10, 7),   # 2 × 5
    (12, 7),   # 2² × 3
    (15, 8),   # 3 × 5
    (16, 8),   # 2⁴
    (100, 14)  # 2² × 5² = 4 + 10
]
```

## 💡 Concepts Mathématiques

### Théorème Fondamental de l'Arithmétique
Chaque entier > 1 peut être représenté de manière unique comme un produit de nombres premiers.

### Stratégie Optimale
Pour obtenir `n` caractères :
1. Factoriser `n` en nombres premiers
2. Pour chaque facteur `p`, effectuer `p` opérations :
   - 1 × Copy All
   - (p-1) × Paste
3. La somme de tous les facteurs donne le minimum d'opérations

### Preuve de l'Optimalité
- **Lemme** : Pour multiplier par `k`, nous avons besoin d'au minimum `k` opérations
- **Théorème** : La factorisation en nombres premiers donne la stratégie optimale
- **Corollaire** : Aucune autre séquence d'opérations ne peut faire mieux

## 🔍 Cas Limites Gérés

### Cas Spéciaux
1. **n = 0 ou n = 1** : Retourne 0 (impossible ou déjà atteint)
2. **Nombres premiers** : Retourne `n` (une seule séquence possible)
3. **Puissances de 2** : Factorisation efficace
4. **Grands nombres** : Algorithme reste efficace grâce à √n

### Gestion d'Erreurs
- Input invalide (n ≤ 1) → retourne 0
- Nombres très grands → algorithme reste efficace
- Pas de débordement d'entier pour les cas pratiques

## 🎓 Objectifs d'Apprentissage

Ce projet démontre :
- **Optimisation Algorithmique** : Transformation d'un problème DP en factorisation
- **Mathématiques Appliquées** : Utilisation des nombres premiers
- **Complexité Algorithmique** : Analyse temporelle et spatiale
- **Problem-Solving** : Identification de patterns mathématiques
- **Implémentation Efficace** : Code concis et performant

## 🔄 Approches Alternatives

### Programmation Dynamique (Moins Efficace)
```python
# Approche DP O(n²) - pas optimale
def minOperations_DP(n):
    if n <= 1:
        return 0
    
    dp = [float('inf')] * (n + 1)
    dp[1] = 0
    
    for i in range(2, n + 1):
        for j in range(2, i + 1):
            if i % j == 0:
                dp[i] = min(dp[i], dp[j] + i // j)
    
    return dp[n]
```

### Comparaison des Approches

| **Approche** | **Complexité Temps** | **Complexité Espace** | **Lisibilité** |
|--------------|----------------------|----------------------|----------------|
| **Factorisation (Utilisée)** | O(√n) | O(1) | Haute |
| Programmation Dynamique | O(n²) | O(n) | Moyenne |
| Récursion avec Mémorisation | O(n²) | O(n) | Faible |

## 🚨 Pièges Courants à Éviter

1. **Mauvaise Compréhension** : Penser que c'est un problème de DP classique
2. **Complexité Excessive** : Utiliser DP au lieu de la factorisation
3. **Cas Limites** : Oublier les cas n ≤ 1
4. **Factorisation Incomplète** : Ne pas gérer le dernier facteur premier
5. **Débordement** : Pour de très grandes valeurs de n

## 🛠️ Extensions Possibles

1. **Version Récursive** : Implémentation récursive avec mémorisation
2. **Optimisation** : Précalcul des nombres premiers
3. **Visualisation** : Afficher la séquence optimale d'opérations
4. **Généralisation** : Étendre à k opérations différentes
5. **Analyse Statistique** : Distribution des opérations pour différents n

## 📚 Références Mathématiques

### Concepts Utilisés
- **Théorème Fondamental de l'Arithmétique**
- **Factorisation en Nombres Premiers**
- **Complexité Algorithmique**
- **Optimisation Combinatoire**

### Applications Similaires
- **Changement de Monnaie** : Algorithme glouton optimal
- **Multiplication de Matrices** : Parenthésage optimal
- **Factorisation RSA** : Sécurité cryptographique

---

**Auteur** : Préparation aux Entretiens Holberton School  
**Langage** : Python 3  
**Algorithme** : Factorisation en Nombres Premiers  
**Complexité** : O(√n) temps, O(1) espace