#include "../latin/adjectives.h"
#include "../latin/declension.h"

int main(void) {
    char *noun = "patria";

    // get the adjective's gender
    int adjectiveGender = getAdjectiveGender(noun);
    printf("%d\n", adjectiveGender);
    return 0;
}