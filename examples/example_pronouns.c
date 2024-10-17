#include "../latin/pronouns.h"

int main() {
    // setup "pronouns" struct
    struct pronouns pronoun = {THIRD_PERSON, PLURAL, ABLATIVE, NEUTRUM};

    // get the personal pronoun
    char *personalPronoun = getPersonalPronoun(pronoun);
    printf("%s\n", personalPronoun);

    // get the reflexive pronoun
    char *reflexivePronoun = getReflexivePronoun(pronoun);
    printf("%s\n", reflexivePronoun);
    return 0;
}