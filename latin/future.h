#ifndef FUTURE_H
#define FUTURE_H

#include "includes.h"
#include "conjugation.h"

char *getStemOfVerbFuture(struct Conjugation conjugation) {
    char *stem = (char *)malloc((strlen(conjugation.verb) + 1) * sizeof(char));
    strcpy(stem, conjugation.verb);
    int length = strlen(stem);

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
        stem[length - 2] = '\0';
        strcat(stem, "b");
    }
    if (isThirdConjugation(conjugation)) {
        stem[length - 3] = '\0';
        if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR)
            strcat(stem, "a");
        else strcat(stem, "e");
    }
    if (isFourthConjugation(conjugation)) {
        stem[length - 2] = '\0';
        if (conjugation.Person == FIRST_PERSON && conjugation.Number == SINGULAR)
            strcat(stem, "a");
        else strcat(stem, "e");
    }
    return stem;
}

char *conjugateVerbFuture(struct Conjugation conjugation) {
    char *stem = getStemOfVerbFuture(conjugation);
    char *conjugatedVerb = "";

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "o");
                    return conjugatedVerb;
                } 
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "is");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "it");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "imus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "itis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "unt");
                    return conjugatedVerb;
                }
        }
    }
    if (isThirdConjugation(conjugation) || isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "m");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "s");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "t");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "mus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "tis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "nt");
                    return conjugatedVerb;
                }
        }
    }
    return "";
}

char *conjugateVerbToBeFuture(struct verbToBe toBe) {
    char *stem = "eri";
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 3) * sizeof(char));

    strcpy(conjugatedVerb, stem);
    int length = strlen(conjugatedVerb);

    switch (toBe.Number) {
        case SINGULAR:
            if (toBe.Person == FIRST_PERSON) {
                conjugatedVerb[length - 1] = '\0';
                strcat(conjugatedVerb, "o");
                break;
            }
            if (toBe.Person == SECOND_PERSON) {
                strcat(conjugatedVerb, "s");
                break;
            }
            if (toBe.Person == THIRD_PERSON) {
                strcat(conjugatedVerb, "t");
                break;
            }
        case PLURAL:
            if (toBe.Person == FIRST_PERSON) {
                strcat(conjugatedVerb, "mus");
                break;
            }
            if (toBe.Person == SECOND_PERSON) {
                strcat(conjugatedVerb, "tis");
                break;
            }
            if (toBe.Person == THIRD_PERSON) {
                conjugatedVerb[length - 1] = '\0';
                strcat(conjugatedVerb, "unt");
            }
    }
    return conjugatedVerb;
}

#endif