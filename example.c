#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"amare", FIRST, THIRD_PERSON, PLURAL};
    char *example = conjugate(conjugation);
    // get the base of the verb:
    printf("%s\n", getBaseOfVerb(conjugation));
    // print out specific conjugation based on type, person and number:
    printf("%s\n", example);
    // check if the conjugation is of first type:
    if (isFirstConjugation(conjugation)) printf("it true");
    else printf("it false");
    return 0;
}