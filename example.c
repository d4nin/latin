#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH};
    // Get the base of the given verb.
    printf("%s", getBaseOfVerb(conjugation));
    return 0;
}