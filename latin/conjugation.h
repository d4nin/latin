#include "includes.h"

enum conjugationType {
    FIRST, 
    SECOND,
    THIRD,
    FOURTH
};

enum person {
    FIRST_PERSON,
    SECOND_PERSON,
    THIRD_PERSON
};

enum number {
    SINGULAR,
    PLURAL
};

struct Conjugation {
    char *verb;
    enum conjugationType type;
    enum person Person;
    enum number Number;
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

char *conjugateVerb(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);

    switch (conjugation.type) {
        case FIRST:
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR) {
                int length = strlen(base);

                char *base1st = (char *)malloc((length + 1) * sizeof(char));
                strcpy(base1st, base);

                base1st[length - 1] = '\0';
                strcat(base1st, "o");
                return base1st;
            }
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "mus");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "s");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "tis");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "t");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "nt");
                return base;
            }
        case SECOND:
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "o");
                return base;
            }
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "mus");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "s");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "tis");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "t");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "nt");
                return base;
            }
        case THIRD:
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "o");
                return base;
            }
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "imus");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "is");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "itis");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "it");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "unt");
                return base;
            }
        case FOURTH:
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "o");
                return base;
            }
            if (conjugation.Person == FIRST_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "mus");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "s");
                return base;
            }
            if (conjugation.Person == SECOND_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "tis");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == SINGULAR) {
                strcat(base, "t");
                return base;
            }
            if (conjugation.Person == THIRD_PERSON && conjugation.Number == PLURAL) {
                strcat(base, "unt");
                return base;
            }
    }
}

bool isFirstConjugation(struct Conjugation conjugation) {
    char *verb = conjugation.verb;
    int length = strlen(verb);

    char lastThree[4];
    lastThree[3] = '\0';
   
    for (int i = 0; i < 3; i++) {
        lastThree[i] = verb[length - 3 + i];
    }
    
    if (strcmp(lastThree, "are") == 0) 
        return true;
    else return false;
}

bool isSecondConjugation(struct Conjugation conjugation) {
    conjugation.Person = SECOND_PERSON;
    conjugation.Number = SINGULAR;

    char *conjugated = conjugate(conjugation);
    int length = strlen(conjugated);
    
    char lastTwo[3];
    lastTwo[2] = '\0';

    for (int i = 0; i < 2; i++) {
        lastTwo[i] = conjugated[length - 2 + i];
    }

    if (strcmp(lastTwo, "is") == 0) 
        return false;
    if (strcmp(lastTwo, "as") == 0) 
        return false;
    else return true;
}

bool isThirdConjugation(struct Conjugation conjugation) {
    conjugation.Person = THIRD_PERSON;
    conjugation.Number = PLURAL;

    char *conjugated = conjugate(conjugation);
    int length = strlen(conjugated);

    char lastFour[5];
    lastFour[4] = '\0';

    for (int i = 0; i < 4; i++) {
        lastFour[i] = conjugated[length - 4 + i];
    } 

    char lastThree[4];
    lastThree[3] = '\0';

    for (int i = 0; i < 3; i++) {
        lastThree[i] = conjugated[length - 3 + i];
    }

    if (strcmp(lastFour, "iunt") == 0)
        return false;
    if (strcmp(lastThree, "ent") == 0 || strcmp(lastThree, "ant") == 0) 
        return false;
    return true;
}

bool isFourthConjugation(struct Conjugation conjugation) {
    char *verb = conjugation.verb;
    int length = strlen(verb);

    char lastThree[4];
    lastThree[3] = '\0';

    for (int i = 0; i < 3; i++) {
        lastThree[i] = verb[length - 3 + i];
    }

    if (strcmp(lastThree, "ire") == 0)
        return true;
    else return false;
}

void conjugateFirst(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);
    int length = strlen(base);
    
    char *base1st = (char *)malloc((length + 1) * sizeof(char));

    strcpy(base1st, base);
    base1st[length - 1] = '\0';

    if (isFirstConjugation(conjugation)) {
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
        printf("%s is not of type 1 conjugation.\n", conjugation.verb);
    }
}

void conjugateSecond(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);

    if (isSecondConjugation(conjugation)) {
        char *base_copy1 = strdup(base);
        char *base_copy2 = strdup(base);
        char *base_copy3 = strdup(base);
        char *base_copy4 = strdup(base);
        char *base_copy5 = strdup(base);

        printf("verb: %s\n", conjugation.verb);
        printf("1.%s\t %s\n", strcat(base, "o"), strcat(base_copy1, "mus"));
        printf("2.%s\t %s\n", strcat(base_copy2, "s"), strcat(base_copy3, "tis"));
        printf("3.%s\t %s\n", strcat(base_copy4, "t"), strcat(base_copy5, "nt"));

        free(base_copy1);
        free(base_copy2);
        free(base_copy3);
        free(base_copy4);
        free(base_copy5);
    } else {
        printf("%s is not of type 2 conjugation.\n", conjugation.verb);
    }
}

void conjugateThird(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);

    if (isThirdConjugation(conjugation)) {
        char *base_copy1 = strdup(base);
        char *base_copy2 = strdup(base);
        char *base_copy3 = strdup(base);
        char *base_copy4 = strdup(base);
        char *base_copy5 = strdup(base);

        printf("verb: %s\n", conjugation.verb);
        printf("1.%s\t %s\n", strcat(base, "o"), strcat(base_copy1, "imus"));
        printf("2.%s\t %s\n", strcat(base_copy2, "is"), strcat(base_copy3, "itis"));
        printf("3.%s\t %s\n", strcat(base_copy4, "it"), strcat(base_copy5, "unt"));

        free(base_copy1);
        free(base_copy2);
        free(base_copy3);
        free(base_copy4);
        free(base_copy5);
    } else {
        printf("%s is not of type 3 conjugation.\n", conjugation.verb);
    }
}

void conjugateFourth(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);

    if (isFourthConjugation(conjugation)) {
        char *base_copy1 = strdup(base);
        char *base_copy2 = strdup(base);
        char *base_copy3 = strdup(base);
        char *base_copy4 = strdup(base);
        char *base_copy5 = strdup(base);

        printf("verb: %s\n", conjugation.verb);
        printf("1.%s\t %s\n", strcat(base, "o"), strcat(base_copy1, "mus"));
        printf("2.%s\t %s\n", strcat(base_copy2, "s"), strcat(base_copy3, "tis"));
        printf("3.%s\t %s\n", strcat(base_copy4, "t"), strcat(base_copy5, "unt"));

        free(base_copy1);
        free(base_copy2);
        free(base_copy3);
        free(base_copy4);
        free(base_copy5);
    } else {
        printf("%s is not of type 4 conjugation.", conjugation.verb);
    }
}