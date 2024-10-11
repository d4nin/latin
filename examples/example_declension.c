#include "../latin/declension.h"

int main() {
    struct Declension declension = {"terra", FIRST, NEUTRUM, PLURAL, ABLATIVE};

    // get the noun's base
    printf("%s\n", getBaseOfNoun(declension));

    // decline the given noun
    printf("%s\n", declineNoun(declension));
    return 0;
}