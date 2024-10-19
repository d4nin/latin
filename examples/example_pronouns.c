#include "../latin/pronouns.h"

int main() {
    // setup "pronouns" struct
    struct pronouns pronoun = {FIRST_PERSON, PLURAL, ACCUSATIVE, NEUTRUM};

    // get the personal pronoun
    char *personalPronoun = getPersonalPronoun(pronoun);
    printf("%s\n", personalPronoun);

    // get the reflexive pronoun
    char *reflexivePronoun = getReflexivePronoun(pronoun);
    printf("%s\n", reflexivePronoun);

    // setup demonstrative pronouns struct
    struct demonstrativePronouns pronouns = {pronoun, "idem, eadem, idem"};

    // get the demonstrative pronoun 
    char *demonstrativePronoun = getDemonstrativePronoun(pronouns);
    printf("%s\n", demonstrativePronoun);
    return 0;
}