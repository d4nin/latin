#include "../latin/declension.h"

void firstDeclension() {
    struct declension first = {"terra", NEUTRUM, PLURAL, ABLATIVE};

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

    // decline the noun of fourth declension
    printf("%s\n", declineNounSecondDeclension(second));
}

void fourthDeclension() {
    struct declension fourth = {"casus", FEMININUM, PLURAL, ABLATIVE}; 

    // check if the noun is of fourth declension
    if (isNounFourthDeclension(fourth))
        printf("True!\n");
    else printf("False!\n");

    // get the fourth declension noun's stem
    printf("%s\n", getStemOfNounFourthDeclension(fourth));

    // decline the noun of fourth declension
    printf("%s\n", declineNounFourthDeclension(fourth));
}

void fifthDeclension() {
    struct declension fifth = {"res", FEMININUM, SINGULAR, NOMINATIVE};

    // check if noun is of fifth declension
    if (isNounFifthDeclension(fifth))
        printf("Correct!\n");
    else printf("Incorrect!\n");
}

int main() {
    // firstDeclension();
    // secondDeclension();
    // fourthDeclension();
    fifthDeclension();
    return 0;
}