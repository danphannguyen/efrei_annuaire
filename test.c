#include <stdbool.h>
#include <stdio.h>
#include "annuaire.h"

static int tests_reussis = 0;
static int tests_total = 0;

static void verifier(const char *titre, bool obtenu, bool attendu) {
  tests_total++;
  if (obtenu == attendu) {
    tests_reussis++;
    printf("[OK]    %s\n", titre);
  } else {
    printf("[ECHEC] %s (obtenu=%s, attendu=%s)\n", titre,
           obtenu ? "true" : "false", attendu ? "true" : "false");
  }
}

int main(void) {
  /* 1. Annuaire vide : les deux approches répondent false */
  verifier("seq_search sur annuaire vide", seq_search("alice@mail.com"), false);
  verifier("hash_search sur annuaire vide", hash_search("alice@mail.com"), false);

  /* 2. Insère les mêmes cinq utilisateurs dans les deux structures */
  const char *emails[5] = {
      "alice@mail.com",
      "bob@mail.com",
      "carole@mail.com",
      "david@mail.com",
      "eve@mail.com"
  };

  for (int i = 0; i < 5; i++) {
    seq_insert(emails[i], i + 1);
    hash_insert(emails[i], i + 1);
  }

  /* 3. Les cinq adresses sont trouvées par les deux approches */
  for (int i = 0; i < 5; i++) {
    char titre_seq[128];
    char titre_hash[128];
    snprintf(titre_seq, sizeof(titre_seq), "seq_search trouve %s", emails[i]);
    snprintf(titre_hash, sizeof(titre_hash), "hash_search trouve %s", emails[i]);

    verifier(titre_seq, seq_search(emails[i]), true);
    verifier(titre_hash, hash_search(emails[i]), true);
  }

  /* 4. Deux adresses absentes ne sont trouvées par aucune des deux */
  verifier("seq_search ne trouve pas inconnu@mail.com", seq_search("inconnu@mail.com"), false);
  verifier("hash_search ne trouve pas inconnu@mail.com", hash_search("inconnu@mail.com"), false);
  verifier("seq_search ne trouve pas mallory@mail.com", seq_search("mallory@mail.com"), false);
  verifier("hash_search ne trouve pas mallory@mail.com", hash_search("mallory@mail.com"), false);

  /* 5. Une adresse dont seule la casse diffère (Alice@mail.com) n'est pas trouvée */
  verifier("seq_search ne trouve pas Alice@mail.com (casse)", seq_search("Alice@mail.com"), false);
  verifier("hash_search ne trouve pas Alice@mail.com (casse)", hash_search("Alice@mail.com"), false);

  /* 6. Compte final */
  printf("\nBilan : %d / %d tests réussis.\n", tests_reussis, tests_total);

  /* 7. Libère la mémoire */
  seq_free();
  hash_free();

  return (tests_reussis == tests_total) ? 0 : 1;
}