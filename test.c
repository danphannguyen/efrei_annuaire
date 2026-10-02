#include <stdio.h>
#include "annuaire.h"

int main(void) {
  for (int i = 1; i <= 40; i++) {
    char email[EMAIL_MAX];
    snprintf(email, EMAIL_MAX, "user%d@mail.com", i);
    seq_insert(email, i);
  }

  seq_free();
  return 0;
}