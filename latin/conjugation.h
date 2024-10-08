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
        case FIRST:
            copy[length - 2] = '\0';
            return copy;
        case SECOND:
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

void *conjugate1st(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);
    int length = strlen(base);
    
    char *base1st = (char *)malloc((length + 1) * sizeof(char));

    strcpy(base1st, base);
    base1st[length - 1] = '\0';

    if (conjugation.type == FIRST) {
        char *base_copy1 = strdup(base);
        char *base_copy2 = strdup(base);
        char *base_copy3 = strdup(base);
        char *base_copy4 = strdup(base);
        char *base_copy5 = strdup(base);
        printf("verb: %s\n", conjugation.verb);
        printf("1. %s\t %s\n", strcat(base1st, "o"), strcat(base_copy3, "mus"));
        printf("2. %s\t %s\n", strcat(base_copy1, "s"), strcat(base_copy4, "tis"));
        printf("3. %s\t %s\n", strcat(base_copy2, "t"), strcat(base_copy5, "nt"));

        free(base_copy1);
        free(base_copy2);
        free(base_copy3);
        free(base_copy4);
        free(base_copy5);
    } else {
        printf("Verb is not of type 1 conjugation.");
    }
}