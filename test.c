#include <stdio.h>
#include "annuaire.h"

int main(void) {
  const char *emails[] = {
      "alice@mail.com",
      "bob@mail.com",
      "carole@mail.com",
      "david@mail.com",
      "eve@mail.com",
      "user1@gmail.com",
      "user2@gmail.com"
  };

  // Taille total du tableau / la taille d'un seul élément pour trouver le nombre d'élément
  int n = sizeof(emails) / sizeof(emails[0]);

  printf("Indices obtenus pour TAILLE_TABLE = %d :\n", TAILLE_TABLE);
  for (int i = 0; i < n; i++) {
    unsigned long h = hachage(emails[i]);
    unsigned long indice = h % TAILLE_TABLE;
    printf("%-18s -> hash: %10lu | indice: %lu\n", emails[i], h, indice);
  }

  return 0;
}