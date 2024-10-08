#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, PLURAL};
    char *example = conjugate(conjugation);
    // get the base of the verb
    printf("%s\n", getBaseOfVerb(conjugation));
    // print out specific conjugation based on type, person and number
    printf("%s\n", example);
    return 0;
}