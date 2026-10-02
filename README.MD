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