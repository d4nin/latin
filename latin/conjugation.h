#ifndef CONJUGATION_H
#define CONJUGATION_H

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

struct verbToBe {
    enum person Person;
    enum number Number;
};

char *getStemOfVerb(struct Conjugation conjugation) {
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
    char *base = getStemOfVerb(conjugation);
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

char *conjugateVerbFirstConjugation(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 3) * sizeof(char));
    strcpy(conjugatedVerb, stem);

    if (isFirstConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    int length = strlen(conjugatedVerb);
                    conjugatedVerb[length - 1] = '\0';
                    strcat(conjugatedVerb, "o");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "s");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "t");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "mus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "tis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "nt");
                    break;
                }
        }
        return conjugatedVerb;
    } else return "";
}

bool isSecondConjugation(struct Conjugation conjugation) {
    conjugation.Person = SECOND_PERSON;
    conjugation.Number = SINGULAR;

    char *conjugated = conjugateVerb(conjugation);
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

    char *conjugated = conjugateVerb(conjugation);
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

char *conjugateVerbToBe(struct verbToBe toBe) {
    char *conjugatedVerb;
    switch (toBe.Number) {
        case SINGULAR:
            if (toBe.Person == FIRST_PERSON) {
                conjugatedVerb = "sum";
                return conjugatedVerb;
            }
            if (toBe.Person == SECOND_PERSON) {
                conjugatedVerb = "es";
                return conjugatedVerb;
            }
            if (toBe.Person == THIRD_PERSON) {
                conjugatedVerb = "est";
                return conjugatedVerb;
            }
        case PLURAL:
            if (toBe.Person == FIRST_PERSON) {
                conjugatedVerb = "sumus";
                return conjugatedVerb;
            }
            if (toBe.Person == SECOND_PERSON) {
                conjugatedVerb = "estis";
                return conjugatedVerb;
            }
            if (toBe.Person == THIRD_PERSON) {
                conjugatedVerb = "sunt";
                return conjugatedVerb;
            }
    }
}

#endif