# 🔢 Palindrome Integer

## 📝 Description
Ce projet implémente une fonction élégante qui vérifie si un entier non signé donné est un palindrome. Un palindrome est un nombre qui se lit de la même façon dans les deux sens (comme 121, 1331, ou 12345654321).

## ⚡ Exigences
- ✅ Écrire une fonction qui vérifie si un entier non signé donné est un palindrome
- 🎯 Prototype: `int is_palindrome(unsigned long n);`
- 📊 Où `n` est le nombre à vérifier
- 🔄 Votre fonction doit retourner `1` si `n` est un palindrome, et `0` sinon
- 🚫 Vous n'êtes pas autorisé à allouer de la mémoire dynamiquement (malloc, calloc, …)

## 📁 Fichiers
- 📋 `palindrome.h` - Fichier d'en-tête contenant le prototype de la fonction
- ⚙️ `0-is_palindrome.c` - Implémentation de la fonction `is_palindrome`
- 🧪 `0-main.c` - Fichier de test pour la fonction

## 🔨 Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

## 🚀 Utilisation
```bash
./palindrome <nombre>
```

## 💡 Exemples
```bash
$ ./palindrome 1
1 is a palindrome.

$ ./palindrome 11
11 is a palindrome.

$ ./palindrome 112
112 is not a palindrome.

$ ./palindrome 121
121 is a palindrome.

$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
```

## 🔍 Explication détaillée

### 1️⃣ Signature de la fonction
`int is_palindrome(unsigned long n)` : La fonction prend un nombre entier non signé `n` et retourne un entier (1 si palindrome, 0 sinon)

### 2️⃣ Variables utilisées
- 💾 `original = n` : Sauvegarde la valeur originale du nombre
- 🔄 `reversed = 0` : Variable pour construire le nombre inversé

### 3️⃣ Algorithme de retournement

🔧 **Principe :** La boucle `while (n > 0)` inverse les chiffres du nombre en les extrayant un par un de droite à gauche et en les reconstruisant de gauche à droite.

**Les 3 étapes à chaque itération :**

1. 🎯 **Extraction :** `n % 10` obtient le chiffre le plus à droite
   - Exemple : 121 % 10 = 1 (dernier chiffre)

2. ➕ **Construction :** `reversed * 10 + (n % 10)` ajoute ce chiffre à la fin du nombre inversé
   - On multiplie par 10 pour "décaler" les chiffres déjà présents vers la gauche
   - Puis on ajoute le nouveau chiffre à droite

3. ➗ **Suppression :** `n /= 10` enlève le dernier chiffre du nombre original
   - Division entière qui "coupe" le dernier chiffre
   - Exemple : 121 / 10 = 12

📊 **Exemple détaillé avec n = 121 :**

| Itération | État initial | n % 10 | reversed * 10 | + (n % 10) | = nouveau reversed | n / 10 | nouveau n |
|-----------|--------------|--------|---------------|------------|-------------------|--------|-----------|
| **1**     | n=121, reversed=0 | 1 | 0 * 10 = 0 | + 1 | = 1 | 121/10 | = 12 |
| **2**     | n=12, reversed=1 | 2 | 1 * 10 = 10 | + 2 | = 12 | 12/10 | = 1 |
| **3**     | n=1, reversed=12 | 1 | 12 * 10 = 120 | + 1 | = 121 | 1/10 | = 0 |

🎯 **Résultat :** reversed = 121, n = 0 (boucle s'arrête)

### 4️⃣ Vérification du palindrome
🔍 `return (original == reversed ? 1 : 0)` : Compare le nombre original avec sa version inversée
- ✅ Retourne 1 si identiques (palindrome), 0 sinon

## 🎯 Exemples d'utilisation
- ✅ `is_palindrome(121)` → retourne 1 (palindrome)
- ❌ `is_palindrome(123)` → retourne 0 (pas palindrome)
- ✅ `is_palindrome(1221)` → retourne 1 (palindrome)

## ⚡ Performance
L'algorithme est efficace avec une **complexité temporelle O(log n)** où n est le nombre de chiffres.

---
*Développé dans le cadre du programme Holberton School* 🎓