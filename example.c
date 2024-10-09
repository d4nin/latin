#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, SINGULAR};
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
    // check if the conjugaiton is of third type:
    if (isThirdConjugation(conjugation)) printf("true\n");
    else printf("false\n");
    return 0;
}