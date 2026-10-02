#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include <stdbool.h>

#define EMAIL_MAX 100
#define TAILLE_TABLE 1024

typedef struct {
  char email[EMAIL_MAX]; /* l'adresse e-mail */
  int id;                /* l'identifiant numerique */
} User;

typedef struct Node {
  char email[EMAIL_MAX];
  int id;
  struct Node *next;
} Node;

void seq_insert(const char *email, int id);
bool seq_search(const char *email);
void seq_free(void);

unsigned long hachage(const char *email);
void hash_insert(const char *email, int id);
bool hash_search(const char *email);
void hash_free(void);

#endif