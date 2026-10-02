#include <stdbool.h>
#include <stdio.h>
#include "annuaire.h"

int main(void) {
  User user;
  user.id = 1;
  // user.email = "helloworld@gmail.com";

  snprintf(user.email, EMAIL_MAX, "%s", "helloworld@gmail.com");

  printf("User ID: %d\n", user.id);
  printf("User Email: %s\n", user.email);
}