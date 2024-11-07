#include "../latin/adjectives.h"
#include "../latin/declension.h"

int main(void) {
    struct declension noun1 = {"patria", FEMININUM, SINGULAR, NOMINATIVE};
    struct declensionSecond noun2 = {"bellum", NEUTRUM, SINGULAR, NOMINATIVE, 1};
    printf("%d\n", getGenderOfAdjective(noun1.noun));
    printf("%d\n", getGenderOfAdjective(noun2.noun));
    return 0;
}