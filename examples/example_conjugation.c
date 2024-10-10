#include "../latin/conjugation.h"

/*
    CODE EXAMPLES FOR WORKING WITH CONJUGATION
*/

int main() {
    // setting up the verb
    struct Conjugation conjugation = {"habere", SECOND, FIRST_PERSON, SINGULAR};
    
    // get the verb's base
    char *base = getBaseOfVerb(conjugation);
    
    // conjugate the verb in the present form
    char *conjugated = conjugate(conjugation);

    printf("verb's base: %s\nconjugated verb: %s\n", base, conjugated);
    
    // check if verb belongs to the first type of conjugation
    if (isFirstConjugation(conjugation))
        printf("True!\n");
    else printf("False.\n");

    // check if verb belongs to the second type of conjugation
    if (isSecondConjugation(conjugation))
        printf("True!\n");
    else printf("False.\n");

    // check if verb belongs to the third type of conjugation
    if (isThirdConjugation(conjugation))
        printf("True!\n");
    else printf("False.\n");

    // check if verb belongs to the fourth type of conjugation
    if (isFourthConjugation(conjugation))
        printf("True!\n");
    else printf("False.\n");

    // print out the entirety of the 1st type of conjugation in the present form
    conjugate1st(conjugation);

    // print out the entirety of the 2nd type of conjugation in the present form
    conjugate2nd(conjugation);
    return 0;
}