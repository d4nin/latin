#ifndef PERFECT_H
#define PERFECT_H

#include "includes.h"
#include "conjugation.h"

char *conjugateVerbPerfectFirstType(struct Conjugation conjugation) {   
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 7) * sizeof(char));

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)
        || isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "vi");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "visti");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "vit");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "vimus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "vistis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "verunt");
                    break;
                }
        }
        return conjugatedVerb;    
    }
    if (isThirdConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "ivi");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "ivisti");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "ivit");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "ivimus");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "ivistis");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "iverunt");
                    break;
                }
        } 
        return conjugatedVerb; 
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

#endif