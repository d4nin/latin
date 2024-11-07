#include "../latin/adjectives.h"
#include "../latin/declension.h"

int main(void) {
    // setting up the adjective struct
    struct adjectives adjective = {"bonus", 2};

    // get the adjective's gender (for first and second declension)
    struct declension noun1 = {"patria", FEMININUM, SINGULAR, NOMINATIVE};
    struct declensionSecond noun2 = {"populus", MASCULINUM, SINGULAR, NOMINATIVE, 1};
    printf("%d\n", getGenderOfAdjective(noun1.noun));
    printf("%d\n", getGenderOfAdjective(noun2.noun));

    // get the adjective's stem (for the first and second declension)
    char *stem = getStemOfAdjective(adjective, noun2.noun);
    printf("%s\n", stem);
    return 0;
}