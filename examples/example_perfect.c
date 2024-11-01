#include "../latin/conjugation.h"
#include "../latin/perfect.h"

int main() {
    struct Conjugation conjugation = {"absolvere", THIRD, THIRD_PERSON, PLURAL};

    // conjugate the verb in the first type of the perfect tense
    char *verbPerfectFirstType = conjugateVerbPerfectFirstType(conjugation);
    printf("%s\n", verbPerfectFirstType);

    // conjugate the verb in the second type of the perfect tense
    char *verbPerfectSecondType = conjugateVerbPerfectSecondType(conjugation);
    printf("%s\n", verbPerfectSecondType);

    // conjugate the verb in the third type of the perfect tense
    char *verbPerfectThirdType = conjugateVerbPerfectFourthType(conjugation);
    printf("%s\n", verbPerfectThirdType);
    return 0;
}