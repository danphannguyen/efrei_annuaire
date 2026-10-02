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




