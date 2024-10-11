#include "../latin/declension.h"

int main() {
    struct Declension declension = {"terra", FIRST, FEMININUM, NOMINATIVE};

    // get the noun's base
    printf("%s\n", getBaseOfNoun(declension));
    return 0;
}