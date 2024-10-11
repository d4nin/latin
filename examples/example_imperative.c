#include "../latin/imperative.h"

int main() {
    struct Conjugation conjugation = {"scribere", THIRD, SECOND_PERSON, PLURAL};

    // get the imperative first form
    printf("%s\n", imperativeFirst(conjugation));
    return 0;
}