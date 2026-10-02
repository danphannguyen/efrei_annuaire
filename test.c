#include <assert.h>
#include <stdio.h>
#include "annuaire.h"

int main(void) {
  // Test 1 : Recherche sur un annuaire vide
  printf("--- Test 3 : Annuaire vide ---\n");
  bool vide_result = seq_search("alice@mail.com");
  printf("Recherche 'alice@mail.com' sur annuaire vide : %s\n", vide_result ? "trouve (FAIL)" : "non trouve (PASS)");
  assert(!vide_result);

  // Test 2 : Insertion de 5 adresses
  printf("\n--- Test 2 : 5 adresses insérées ---\n");
  seq_insert("alice@mail.com", 1);
  seq_insert("bob@mail.com", 2);
  seq_insert("charlie@mail.com", 3);
  seq_insert("david@mail.com", 4);
  seq_insert("eve@mail.com", 5);

  // 3 recherches qui doivent réussir (true)
  printf("Recherches qui doivent reussir :\n");
  bool r1 = seq_search("alice@mail.com");
  printf("  - 'alice@mail.com'   : %s\n", r1 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r1);

  bool r2 = seq_search("charlie@mail.com");
  printf("  - 'charlie@mail.com' : %s\n", r2 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r2);

  bool r3 = seq_search("eve@mail.com");
  printf("  - 'eve@mail.com'     : %s\n", r3 ? "trouve (PASS)" : "non trouve (FAIL)");
  assert(r3);

  // 2 recherches qui doivent échouer (false)
  printf("Recherches qui doivent echouer :\n");
  bool r4 = seq_search("inconnu@mail.com");
  printf("  - 'inconnu@mail.com' : %s\n", r4 ? "trouve (FAIL)" : "non trouve (PASS)");
  assert(!r4);

  bool r5 = seq_search("mallory@mail.com");
  printf("  - 'mallory@mail.com' : %s\n", r5 ? "trouve (FAIL)" : "non trouve (PASS)");
  assert(!r5);

  seq_free();
  printf("\nTous les tests sont passes avec succes.\n");
  return 0;
}