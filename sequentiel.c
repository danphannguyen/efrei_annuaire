#include "annuaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static User *annuaire = NULL;
static int taille = 0;
static int capacite = 0;

void seq_insert(const char *email, int id) {
  // Si la taille du tableau atteint sa capacité max
  if (taille == capacite) {
    int nouvelle_capacite;

    if (capacite == 0) { // Si la capacité est égal à 0 (initialisation)
      nouvelle_capacite = 16;
    } else {
      nouvelle_capacite = capacite * 2;
    }
    User *tmp = realloc(annuaire, (size_t)nouvelle_capacite * sizeof(User));
    if (tmp == NULL) {
      perror("realloc");
      exit(EXIT_FAILURE);
    }
    annuaire = tmp;
    capacite = nouvelle_capacite;
  }
  snprintf(annuaire[taille].email, EMAIL_MAX, "%s", email);
  annuaire[taille].id = id;
  taille++;
  // inclure un printf si besoin pour capacite et taille
  // printf("Capacite : %d / Taille : %d \n", capacite, taille);
}

void seq_free(void) {
  free(annuaire);
  annuaire = NULL;
  taille = 0;
  capacite = 0;
}

bool seq_search(const char *email) {
  for (int i = 0; i < taille; i++) {
    if (strcmp(email, annuaire[i].email) == 0) {
      return true;
    }
  }
  return false;
}