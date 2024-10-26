#ifndef IMPERFECT_H
#define IMPERFECT_H

#include "includes.h"
#include "conjugation.h"

char *getStemOfVerbImperfect(struct Conjugation conjugation) {
    char *verb = (char *)malloc((strlen(conjugation.verb) + 2) * sizeof(char));
    strcpy(verb, conjugation.verb);
    int length = strlen(verb);

    if (isFirstConjugation(conjugation) || isThirdConjugation(conjugation)) {
        verb[length - 2] = '\0';
        strcat(verb, "b");
        return verb;
    }
    if (isThirdConjugation(conjugation)) {
        verb[length - 3] = '\0';
        strcat(verb, "eb");
        return verb;
    }
    if (isFourthConjugation(conjugation)) {
        verb[length - 2] = '\0';
        strcat(verb, "eb");
        return verb;
    }
}

char *conjugateVerbImperfect(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb;

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "bam");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "bas");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "bat");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "bamus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "batis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "bant");
                    return conjugatedVerb;
                }
        }
    }
    if (isThirdConjugation(conjugation) || isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "ebam");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "ebas");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "ebat");
                    return conjugatedVerb;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    conjugatedVerb = strcat(stem, "ebamus");
                    return conjugatedVerb;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    conjugatedVerb = strcat(stem, "ebatis");
                    return conjugatedVerb;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    conjugatedVerb = strcat(stem, "ebant");
                    return conjugatedVerb;
                }
        }
    }
    return "";
}

char *conjugateVerbToBeImperfect(struct verbToBe toBe) {
    char *stem = "era";
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 4) * sizeof(char));

    strcpy(conjugatedVerb, stem);

    switch (toBe.Number) {
        case SINGULAR:
            if (toBe.Person == FIRST_PERSON) {
                strcat(conjugatedVerb, "m");
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
                strcat(conjugatedVerb, "nt");
                break;
            }
    }
    return conjugatedVerb;
}

#endif