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

    // decline the noun of fourth declension
    printf("%s\n", declineNounSecondDeclension(second));
}

void fourthDeclension() {
    // setting up noun of fourth declension
    struct declensionFourth fourth = {"casus", FEMININUM, PLURAL, ABLATIVE}; 

    // check if the noun is of fourth declension
    if (isNounFourthDeclension(fourth))
        printf("True!\n");
    else printf("False!\n");

    // get the fourth declension noun's stem
    printf("%s\n", getStemOfNounFourthDeclension(fourth));

    // decline the noun of fourth declension
    printf("%s\n", declineNounFourthDeclension(fourth));
}

int main() {
    firstDeclension();
    secondDeclension();
    fourthDeclension();
    return 0;
}