#include "../latin/declension.h"

void firstDeclension() {
    // setting up noun of first declension
    struct declensionFirst first = {"terra", NEUTRUM, PLURAL, ABLATIVE};

    // check if the noun is of first declension
    if (isNounFirstDeclension(first))
        printf("True!\n");
    else printf("False!\n");

    // get the stem of noun of first declension
    char *baseFirst = getStemOfNounFirstDeclension(first);
    printf("%s\n", baseFirst);

    // decline the noun of first declension
    printf("%s\n", declineNounFirstDeclension(first));
}

void secondDeclension() {
    // setting up noun of second declension
    struct declensionSecond second = {"bellum", NEUTRUM, PLURAL, GENITIVE, 1};
    
    // check if the noun is of second declension
    if (isNounSecondDeclension(second))
        printf("Correct!\n");
    else printf("Incorrect!\n");
    
    // get the second declension noun's stem 
    printf("%s\n", getStemOfNounSecondDeclension(second));

    printf("%s\n", declineNounSecondDeclension(second));
}

int main() {
    firstDeclension();
    secondDeclension();
    return 0;
}