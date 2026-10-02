#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include <stdbool.h>
#define EMAIL_MAX 100

typedef struct {
  char email[EMAIL_MAX]; /* l'adresse e-mail */
  int id; /* l'identifiant numerique */
} User;
#endif