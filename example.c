#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"audire", THIRD, SECOND_PERSON, PLURAL};
    char *example = conjugate(conjugation);
    // get the base of the verb:
    printf("%s\n", getBaseOfVerb(conjugation));
    // print out specific conjugation based on type, person and number:
    printf("%s\n", example);
    // check if the conjugation is of first type:
    if (isFirstConjugation(conjugation)) printf("it true\n");
    else printf("it false\n");
    // check if the conjugation is of second type:
    if (isSecondConjugation(conjugation)) printf("yep it is");
    else printf("nope");
    return 0;
}