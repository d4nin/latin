#include <string.h>
#include <stdlib.h>
enum conjugationType {
    FIRST, 
    SECOND,
    THIRD,
    FOURTH
};

struct Conjugation {
    const char *verb;
    enum conjugationType type;
};

char *getBaseOfVerb(struct Conjugation conjugation) {
    const char *verb = conjugation.verb;
    int length = strlen(verb);

    char *copy = (char *)malloc((length + 1) * sizeof(char)); 

    strcpy(copy, verb);

    switch (conjugation.type) {
        case FIRST || SECOND:
            copy[length - 2] = '\0';
            return copy;
        case THIRD:
            copy[length - 3] = '\0';
            return copy;
        case FOURTH:
            copy[length - 2] = '\0';
            return copy;
    }
}

const char *conjugate(struct Conjugation conjugation) {
    const char *verb = conjugation.verb;

}