#include "../latin/declension.h"

int main() {
    // setting up noun of first declension
    struct declensionFirst first = {"terra", NEUTRUM, SINGULAR, NOMINATIVE};

    // get the base of noun of first declension
    char *baseFirst = getStemOfNounFirstDeclension(first);
    printf("%s\n", baseFirst);

    // check if noun is of first declension
    if (isNounFirstDeclension(first))
        printf("it true\n");
    else printf("it false :(\n");
}