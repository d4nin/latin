#include <stdio.h>
#include "latin/conjugation.h"

int main() {
    struct Conjugation conjugation = {"amare", FIRST};
    printf("%s\n", getBaseOfVerb(conjugation));
    conjugate1st(conjugation);
    return 0;
}