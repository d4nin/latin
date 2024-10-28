#include "../latin/conjugation.h"
#include "../latin/imperfect.h"

int main() {
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, PLURAL};

    // get the verb's stem in the imperfect tense
    char *stemImperfect = getStemOfVerbImperfect(conjugation);
    printf("%s\n", stemImperfect);

    // conjugate the verb in the imperfect tense
    char *conjugationImperfect = conjugateVerbImperfect(conjugation);
    printf("%s\n", conjugationImperfect);

    // conjugate the verb in the imperfect tense per each conjugation
    printf("%s\n", conjugateVerbFirstConjugation(conjugation));
    printf("%s\n", conjugateVerbSecondConjugation(conjugation));
    printf("%s\n", conjugateVerbThirdConjugation(conjugation));
    printf("%s\n", conjugateVerbFourthConjugation(conjugation));

    
}