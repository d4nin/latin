#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"amare", FIRST, THIRD_PERSON, SINGULAR};
    char *example = conjugate(conjugation);
    // get the base of the verb:
    printf("%s\n", getBaseOfVerb(conjugation));

    // print out specific conjugation based on type, person and number:
    printf("%s\n", example);

    // check if the conjugation is of first type:
    if (isFirstConjugation(conjugation)) printf("true\n");
    else printf("false\n");

    // check if the conjugation is of second type:
    if (isSecondConjugation(conjugation)) printf("true\n");
    else printf("false\n");

    // check if the conjugation is of third type:
    if (isThirdConjugation(conjugation)) printf("true\n");
    else printf("false\n");

    // check if the conjugation is of fourth type:
    if (isFourthConjugation(conjugation)) printf("truer\n");
    else printf("falser\n");
    return 0;
}