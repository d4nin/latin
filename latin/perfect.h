#ifndef PERFECT_H
#define PERFECT_H

#include "includes.h"
#include "conjugation.h"

char *getStemOfVerbPerfect(struct Conjugation conjugation, int perfectType) {
    char *stem = (char *)malloc((strlen(conjugation.verb) + 1) * sizeof(char));
    int length = strlen(conjugation.verb);
    strcpy(stem, conjugation.verb);

    switch (perfectType) {
        case 1:
            if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)
                || isFourthConjugation(conjugation)) {
                stem[length - 2] = '\0';
                strcat(stem, "v");
                break;
            }
            if (isThirdConjugation(conjugation)) {
                stem[length - 3] = '\0';
                strcat(stem, "iv");
                break;
            }
    }
    return stem;
}

char *conjugateVerbPerfectFirstType(struct Conjugation conjugation) {   
    char *stem = getStemOfVerbPerfect(conjugation, 1);
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 7) * sizeof(char));

    switch (conjugation.Number) {
        case SINGULAR:
            if (conjugation.Person == FIRST_PERSON) {
                conjugatedVerb = strcat(stem, "i");
                break;
            }
            if (conjugation.Person == SECOND_PERSON) {
                conjugatedVerb = strcat(stem, "isti");
                break;
            }
            if (conjugation.Person == THIRD_PERSON) {
                conjugatedVerb = strcat(stem, "it");
                break;
            }
        case PLURAL:
            if (conjugation.Person == FIRST_PERSON) {
                conjugatedVerb = strcat(stem, "imus");
                break;
            }
            if (conjugation.Person == SECOND_PERSON) {
                conjugatedVerb = strcat(stem, "istis");
                break;
            }
            if (conjugation.Person == THIRD_PERSON) {
                conjugatedVerb = strcat(stem, "erunt");
                break;
            }
        }
    return conjugatedVerb;    
}

char *conjugateVerbPerfectSecondType(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(conjugation.verb) + 5) * sizeof(char));

    if (isSecondConjugation(conjugation)) {
        int length = strlen(stem);
        stem[length - 1] = '\0';
        strcat(stem, "u");

        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "i");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "isti");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "it");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "imus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "istis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "erunt");
                    break;
                }
        }
        return conjugatedVerb;
    }
    if (isThirdConjugation(conjugation)) {
        strcat(stem, "u");
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "i");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "isti");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "it");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "imus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "istis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "erunt");
                    break;
                }
        }
        return conjugatedVerb;
    }
    return "";
}

char *conjugateVerbPerfectThirdType(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(conjugation.verb) + 5) * sizeof(char));

    if (isThirdConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "i");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "isti");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "it");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "imus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "istis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "erunt");
                    break;
                }
        }
    } else conjugatedVerb = "";
    return conjugatedVerb;
}

#endif