#ifndef IMPERFECT_H
#define IMPERFECT_H

#include "includes.h"
#include "conjugation.h"

char *getStemOfVerbImperfect(struct Conjugation conjugation) {
    char *verb = (char *)malloc((strlen(conjugation.verb) + 2) * sizeof(char));
    strcpy(verb, conjugation.verb);
    int length = strlen(verb);

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
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
    char *stem = getStemOfVerbImperfect(conjugation);
    char *conjugatedVerb;

    switch (conjugation.Number) {
        case SINGULAR:
            if (conjugation.Person == FIRST_PERSON) {
                conjugatedVerb = strcat(stem, "am");
                break;
            }
            if (conjugation.Person == SECOND_PERSON) {
                conjugatedVerb = strcat(stem, "as");
                break;
            }
            if (conjugation.Person == THIRD_PERSON) {
                conjugatedVerb = strcat(stem, "at");
                break;
            }
        case PLURAL:
            if (conjugation.Person == FIRST_PERSON) {
                conjugatedVerb = strcat(stem, "amus");
                break;
            }
            if (conjugation.Person == SECOND_PERSON) {
                conjugatedVerb = strcat(stem, "atis");
                break;
            }
            if (conjugation.Person == THIRD_PERSON) {
                conjugatedVerb = strcat(stem, "ant");
                break;
            }
    }
    return conjugatedVerb;
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