#include <assert.h>
#include <stdio.h>
#include "annuaire.h"

int main(void) {
  printf("=== Test 1 : Annuaire vide ===\n");
  bool vide = hash_search("alice@mail.com");
  printf("Recherche 'alice@mail.com' sur table vide : %s\n", vide ? "trouve (FAIL)" : "non trouve (PASS)");
  assert(!vide);

  printf("\n=== Test 2 : 5 adresses insérées ===\n");
  hash_insert("alice@mail.com", 1);
  hash_insert("bob@mail.com", 2);
  hash_insert("carole@mail.com", 3);
  hash_insert("david@mail.com", 4);
  hash_insert("eve@mail.com", 5);

  printf("Recherches qui doivent réussir :\n");
  bool r1 = hash_search("alice@mail.com");
  printf("  - alice@mail.com   : %s\n", r1 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r1);

  bool r2 = hash_search("carole@mail.com");
  printf("  - carole@mail.com  : %s\n", r2 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r2);

  bool r3 = hash_search("eve@mail.com");
  printf("  - eve@mail.com     : %s\n", r3 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r3);

  printf("Recherches qui doivent échouer :\n");
  bool r4 = hash_search("inconnu@mail.com");
  printf("  - inconnu@mail.com : %s\n", !r4 ? "non trouve (PASS)" : "trouve (FAIL)");
  assert(!r4);

  bool r5 = hash_search("mallory@mail.com");
  printf("  - mallory@mail.com : %s\n", !r5 ? "non trouve (PASS)" : "trouve (FAIL)");
  assert(!r5);

  hash_free();
  printf("\nTous les tests normaux ont réussi !\n");
  return 0;
}