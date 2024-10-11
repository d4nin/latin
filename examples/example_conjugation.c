#include "../latin/conjugation.h"

/*
    CODE EXAMPLES FOR WORKING WITH CONJUGATION
*/

int main() {
    // setting up the verb
    struct Conjugation conjugation = {"legere", THIRD, THIRD_PERSON, SINGULAR};
    
    // get the verb's base
    char *base = getBaseOfVerb(conjugation);
    
    // conjugate the verb in the present form
    char *conjugated = conjugateVerb(conjugation);

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
    conjugateFirst(conjugation);

    // print out the entirety of the 2nd type of conjugation in the present form
    conjugateSecond(conjugation);

    // print out the entirety of the 3rd type of conjugation in the present form
    conjugateThird(conjugation);

    // print out hte entirety of the 4th type of conjugation in the present form
    conjugateFourth(conjugation);
    return 0;
}