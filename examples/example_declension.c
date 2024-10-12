#include "../latin/declension.h"

void firstDeclension() {
    // setting up noun of first declension
    struct declensionFirst first = {"terra", NEUTRUM, PLURAL, ABLATIVE};

    // check if the noun is of first declension
    if (isNounFirstDeclension(first))
        printf("True!\n");
    else printf("False!\n");

    // get the base of noun of first declension
    char *baseFirst = getStemOfNounFirstDeclension(first);
    printf("%s\n", baseFirst);

    // decline the noun of first declension
    printf("%s\n", declineNounFirstDeclension(first));
}

void secondDeclension() {
    // setting up noun of second declension
    struct declensionSecond second = {"bellum", MASCULINUM, SINGULAR, NOMINATIVE, 0};
    // check if the noun is of second declension
    if (isNounSecondDeclension(second))
        printf("Correct!\n");
    else printf("Incorrect!\n");
}

int main() {
    firstDeclension();
    secondDeclension();
    return 0;
}