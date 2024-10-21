#include "../latin/imperative.h"

int main() {
    struct Conjugation conjugation = {"scribere", THIRD, THIRD_PERSON, PLURAL};

    // get the imperative first form
    printf("%s\n", imperativeFirst(conjugation));

    // get the imperative (future) second form
    printf("%s\n", imperativeSecond(conjugation)); 
    return 0;
}