#include "../latin/declension.h"

int main() {
    // setting up noun of first declension
    struct declensionFirst first = {"terra", FEMININUM, SINGULAR, NOMINATIVE};
    
    // get the base of noun of first declension
    char *baseFirst = getStemOfNounFirstDeclension(first);
    printf("%s\n", baseFirst);
}