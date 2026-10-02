#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include <stdbool.h>
#define EMAIL_MAX 100

typedef struct {
  char email[EMAIL_MAX]; /* l'adresse e-mail */
  int id; /* l'identifiant numerique */
} User;

void seq_insert(const char *email, int id);
bool seq_search(const char *email);
void seq_free(void);

#endif