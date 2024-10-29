#include "../latin/conjugation.h"
#include "../latin/perfect.h"

int main() {
    struct Conjugation conjugation = {"scribere", THIRD, THIRD_PERSON, PLURAL};

    // conjugate the verb in the first type of the perfect tense
    char *verbPerfectFirstType = conjugateVerbPerfectFirstType(conjugation);
    printf("%s\n", verbPerfectFirstType);

    return 0;
}