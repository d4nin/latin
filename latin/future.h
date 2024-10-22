#ifndef FUTURE_H
#define FUTURE_H

#include "includes.h"
#include "conjugation.h"

char *conjugateVerbFuture(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = "";

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "bo");
                    return conjugatedVerb;
                } 
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "bis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "bit");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "bimus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "bitis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "bunt");
                    return conjugatedVerb;
                }
        }
    }
    if (isThirdConjugation(conjugation) || isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "am");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "es");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "et");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "emus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "etis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "ent");
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