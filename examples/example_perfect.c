#include "../latin/conjugation.h"
#include "../latin/perfect.h"

int main() {
    struct Conjugation conjugation = {"habere", SECOND, FIRST_PERSON, PLURAL};

    // conjugate the verb in the first type of the perfect tense
    char *verbPerfectFirstType = conjugateVerbPerfectFirstType(conjugation);
    printf("%s\n", verbPerfectFirstType);

    // conjugate the verb in the second type of the perfect tense
    char *verbPerfectSecondType = conjugateVerbPerfectSecondType(conjugation);
    printf("%s\n", verbPerfectSecondType);
    return 0;
}