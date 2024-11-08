#include "../latin/adjectives.h"
#include "../latin/declension.h"

int main(void) {
    // setting up the adjective struct
    struct adjectives adjective = {"bonus", 2, MASCULINUM, SINGULAR, DATIVE};

    // get the adjective's gender (for first and second declension)
    struct declension noun1 = {"patria", FEMININUM, PLURAL, ABLATIVE};
    struct declensionSecond noun2 = {"populus", MASCULINUM, SINGULAR, DATIVE, 0};
    printf("%d\n", getGenderOfAdjective(noun1.noun));
    printf("%d\n", getGenderOfAdjective(noun2.noun));

    // get the adjective's stem (for the first and second declension)
    char *stem = getStemOfAdjective(adjective, noun2.noun);
    printf("%s\n", stem);

    // decline the adjective of first declension
    printf("%s %s\n", declineAdjectiveFirstDeclension(adjective, noun1.noun), declineNounFirstDeclension(noun1));
    // decline the adjectiver of second declension
    printf("%s %s\n", declineAdjectiveSecondDeclension(adjective, noun2.noun), declineNounSecondDeclension(noun2));
    return 0;
}