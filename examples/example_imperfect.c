#include "../latin/conjugation.h"
#include "../latin/imperfect.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, PLURAL};

    // get the verb's stem in the imperfect tense
    char *stemImperfect = getStemOfVerbImperfect(conjugation);
    printf("%s\n", stemImperfect);

    char *conjugationImperfect = conjugateVerbImperfect(conjugation);
    printf("%s\n", conjugationImperfect);
}