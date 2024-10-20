#include "../latin/conjugation.h"
#include "../latin/imperfect.h"

/*
    CODE EXAMPLES FOR WORKING WITH CONJUGATION
*/

int main() {
    // setting up the verb
    struct Conjugation conjugation = {"punire", FOURTH, THIRD_PERSON, PLURAL};
    
    // get the verb's base
    char *base = getStemOfVerb(conjugation);
    
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

    // conjugate the verb in the imperfect tense
    char *imperfect = conjugateVerbPerfect(conjugation);
    printf("%s\n", imperfect);
    return 0;
}