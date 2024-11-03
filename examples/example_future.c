#include "../latin/future.h"
#include "../latin/conjugation.h"

int main(void) {
    struct Conjugation conjugation = {"audire", FOURTH, FIRST_PERSON, SINGULAR};

    // get the verb's stem in the future tense
    char *verbStemFuture = getStemOfVerbFuture(conjugation);
    printf("%s\n", verbStemFuture);
    // conjugate the verb in the future tense
    char *verbFuture = conjugateVerbFuture(conjugation);
    printf("%s\n", verbFuture);
    return 0;
}