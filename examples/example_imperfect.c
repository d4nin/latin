#include "../latin/conjugation.h"
#include "../latin/imperfect.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH, FIRST_PERSON, SINGULAR};

    // get the verb's stem in the imperfect tense
    char *stemImperfect = getStemOfVerbImperfect(conjugation);
    printf("%s\n", stemImperfect);
}