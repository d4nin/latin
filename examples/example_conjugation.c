#include "../latin/conjugation.h"
#include "../latin/imperfect.h"
#include "../latin/future.h"

/*
    CODE EXAMPLES FOR WORKING WITH CONJUGATION
*/

void verbToBe() {
    // setting up the verb "to be"
    struct verbToBe toBe = {THIRD_PERSON, PLURAL};

    // conjugate the verb "to be" in the present tense
    char *present = conjugateVerbToBe(toBe);
    printf("%s\n", present);

    // conjugate the verb "to be" in the imperfect tense
    char *imperfect = conjugateVerbToBeImperfect(toBe);
    printf("%s\n", imperfect);

    // conjugate the verb "to be" in the future tense
    char *future = conjugateVerbToBeFuture(toBe);
    printf("%s\n", future);
}

int main() {
    verbToBe();

    // setting up the verb
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, PLURAL};
    
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

    char *verb = "amant";
    if (isVerbPresentTense(verb)) 
        printf("Present tense.\n");
    else printf("Not present tense.\n");

    // conjugate verbs of the first conjugation
    char *first = conjugateVerbFirstConjugation(conjugation);
    printf("%s\n", first);

    // conjugate verbs of the second conjugation
    char *second = conjugateVerbSecondConjugation(conjugation);
    printf("%s\n", second);

    // conjugate verbs of the third conjugation
    char *third = conjugateVerbThirdConjugation(conjugation);
    printf("%s\n", third);

    // conjugate verbs of the fourth conjugation
    char *fourth = conjugateVerbFourthConjugation(conjugation);
    printf("%s\n", fourth);

    // conjugate the verb in the imperfect tense
    char *imperfect = conjugateVerbImperfect(conjugation);
    printf("%s\n", imperfect);

    char *future = conjugateVerbFuture(conjugation);
    printf("%s\n", future);
    return 0;
}