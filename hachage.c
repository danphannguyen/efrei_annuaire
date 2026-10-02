#include "annuaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TABLE 1024

unsigned long hachage(const char *email) {
  unsigned long h = 5381;
  int c;
  while ((c = (unsigned char)*email++))
    h = ((h * 33) + c) & 0xFFFFFFFF;
  return h;
}