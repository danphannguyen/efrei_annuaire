# TP - Annuaire

## Exo 0

4. Remplacez volontairement snprintf(u.email, EMAIL_MAX, "%s", "alice@mail.com") par u.email = "alice@mail.com". Recompilez et notez le message d’erreur.

```text
test.c:8:14: error: array type 'char[100]' is not assignable
    8 |   user.email = "helloworld@gmail.com";
      |   ~~~~~~~~~~ ^
```


5. Question : pourquoi ne peut-on pas affecter une chaîne à un tableau de char avec = ?
-> Le type `string` n'existant pas en C, l'opérateur `=` ne copie pas de bloc de données vers un tableau après son initialisation, il faut obligatoirement copier les octets en mémoire avec une fonction comme `snprintf` ou `strcpy`.

## Exo 1

| Point | Votre réponse |
| :--- | :--- |
| Entrées | Une adresse e-mail sous forme de chaîne de caractères (`const char *`). |
| Sorties | Un booléen (`true` si l'e-mail existe déjà dans l'annuaire, `false` sinon). |
| Contraintes | Latence minimale car bloquante pour l'utilisateur et absence totale de doublon autorisé. |
| Volume | Un nombre d'utilisateurs potentiellement très élevé (de quelques milliers à plusieurs millions) en croissance continue. |
| Fréquence | Très forte fréquence de lecture/recherche (à chaque tentative d'inscription) par rapport aux écritures/insertions. |

2. Question : parmi les cinq points, lesquels vous aideraient à choisir entre deux structures de données ? Lesquels ne vous apprennent rien sur ce choix ?
-> Les points : Fréquence, Contrainte, Volume
-> Entrées et Sorties


3. Question : deux annuaires ont les mêmes entrées et la même sortie, l’un contient 30 employés consultés
deux fois par jour, l’autre 5 millions de comptes interrogés mille fois par seconde. Quels sont les deux
points de la grille qui les distinguent ?
-> Volume et Fréquence

## Exo 2

3. Realloc à été appelé 3 fois pour 40 utilisateurs et 7 fois pour 1000 utilisateurs

## Exo 3

4. Remplacez strcmp(...) == 0 par ... == email. Le programme compile-t-il ? Que renvoie la recherche
? Notez précisément ce qui se passe.
-> Assertion failed: (r1), function main, file test.c, line 24.
-> Le soucis est que "email == annuaire[i].email" va comparer les adresses et non le contenu

5. Question : combien de comparaisons seq_search effectue-t-elle sur un annuaire de n utilisateurs, dans
le cas favorable, dans le cas moyen, puis dans le cas défavorable ? Décrivez à chaque fois quelle donnée
produit ce cas.
-> Dans le cas favorable : 1 
(L'adresse recherchée se trouve en première position dans le tableau)
-> Dans le cas moyen : environ n / 2 
(L'adresse recherchée est présente dans l'annuaire et située vers le milieu du tableau)
-> Dans le cas défavorable : n
(L'adresse recherchée est en toute dernière position)

## Exo 4

0. Une fonction de hachage va prendre une chaine de caractère et y appliquer un calcul pour obtenir une autre chaîne de cartère. Ce calcul est déterministe car pour un même string la sortie sera TOUJOURS la même.

2. Dans un main , aﬀichez l’indice obtenu pour les cinq adresses alice@mail.com, bob@mail.com,
carole@mail.com, david@mail.com, eve@mail.com, avec TAILLE_TABLE valant 1024.
```text
Indices obtenus pour TAILLE_TABLE = 1024 :
alice@mail.com     -> hash:  424300563 | indice: 19
bob@mail.com       -> hash: 1403682920 | indice: 104
carole@mail.com    -> hash: 2094645995 | indice: 747
david@mail.com     -> hash: 4201840829 | indice: 189
eve@mail.com       -> hash: 2553102517 | indice: 181
user1@gmail.com    -> hash:  444242892 | indice: 972
user2@gmail.com    -> hash: 2681688333 | indice: 269
```

3. Aﬀichez l’indice de alice@mail.com trois fois de suite. Que constatez-vous, et pourquoi est-ce indispens-
able ?
-> Il est le même, cela est indispensable pour pouvoir le rechercher car si la sortie n'est pas constante pour une même entrée, la recherche serait impossible.

4. Comparez les indices de user1@mail.com et user2@mail.com. Sont-ils voisins ?
-> Non ils ne sont pas voisin 
```
user1@gmail.com    -> hash:  444242892 | indice: 972
user2@gmail.com    -> hash: 2681688333 | indice: 269
```

5. Remplacez unsigned long par int dans la fonction et dans la variable qui reçoit l’indice, puis réaﬀichez les indices des cinq adresses. Deux d’entre elles changent de comportement : lesquelles, et que vaut alors
leur indice ? Que se passerait-il si on utilisait cet indice pour accéder au tableau ?
-> Les deux adresses qui changent de comportement sont david@mail.com et eve@mail.com.
Leurs nouveaux indices valent :
- david@mail.com : indice = -835 (au lieu de 189)
- eve@mail.com   : indice = -843 (au lieu de 181)

-> L'indice étant négatif, tenter d'accéder au tableau (ex: `table[-835]`) ce qui provoque un accès mémoire hors limites, menant à un comportement indéterminé, à la corruption de mémoire ou à un plantage immédiat par `Segmentation Fault`.


6. Question : deux adresses différentes peuvent-elles donner le même indice ? Si oui, est-ce un défaut de la
fonction ?
-> Oui c'est possible (c'est une collision), et non ce n'est pas un défaut, en cas de collision la nouvelle valeur sera stockée au début du bucket

## Exo 5

2. Testez avec les mêmes cinq adresses que l’exercice 3, plus les deux recherches qui doivent échouer, plus le
cas de l’annuaire vide.

```
=== Test 1 : Annuaire vide ===
Recherche 'alice@mail.com' sur table vide : non trouve (PASS)
=== Test 2 : 5 adresses insérées ===
Recherches qui doivent réussir :
  - alice@mail.com   : trouve (PASS)
  - carole@mail.com  : trouve (PASS)
  - eve@mail.com     : trouve (PASS)
Recherches qui doivent échouer :
  - inconnu@mail.com : non trouve (PASS)
  - mallory@mail.com : non trouve (PASS)
Tous les tests normaux ont réussi !
```

3. Inversez volontairement les deux lignes de l’insertion en tête. Insérez trois adresses tombant dans la même
alvéole, puis recherchez-les. Que se passe-t-il ?
-> En échangeant ses deux lignes le soucis est que le tableau va boucler sur lui même car on dit que le pointeur commençant le tableau est n et que le n->next = table[i] donc au début du tableau.
```
table[i] = n;
n->next = table[i];
```

4. Question : hash_free doit libérer chaque nœud de chaque chaîne. Pourquoi faut-il mémoriser n->next
dans une variable avant d’appeler free(n) ?
Car si on ne sauvegarde pas n->next avant d'appeler free(n), on perd la valeur du n->next donc on perdra l'adresse du prochain noeud

## Exo 6
