#include "../latin/conjugation.h"
#include "../latin/passive.h"

int main(void) {
    struct Conjugation conjugation = {"audire", FOURTH, THIRD_PERSON, PLURAL};

    // get the passive voice of a verb in the present tense
    char *passivePresent = conjugateVerbPassive(conjugation);
    printf("%s\n", passivePresent);

    char *verb = "audiuntur";
    if (isVerbPassiveVoice(verb))
        printf("It's in the passive voice.\n");
    else printf("It's not in the passive voice.");
    return 0;
}