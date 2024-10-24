#ifndef PASSIVE_H
#define PASSIVE_H

#include "includes.h"
#include "conjugation.h"

char *conjugateVerbPassive(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 1) * sizeof(char));
    strcpy(conjugatedVerb, stem);

    if (isFirstConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    int length = strlen(conjugatedVerb);
                    conjugatedVerb[length - 1] = '\0';

                    strcat(conjugatedVerb, "or");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "ris");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "tur");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "mur");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "mini");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "ntur");
                    break;
                }
        }
    }
    if (isSecondConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "or");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "ris");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "tur");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "mur");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "mini");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "ntur");
                    break;
                }
        }
    }
    if (isThirdConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "or");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "eris");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "itur");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "imur");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "imini");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "untur");
                    break;
                }
        }
    }
    if (isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "or");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "ris");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "tur");
                    break;
                }
            case PLURAL:
                if (conjugation.Person == FIRST_PERSON) {
                    strcat(conjugatedVerb, "mur");
                    break;
                }
                if (conjugation.Person == SECOND_PERSON) {
                    strcat(conjugatedVerb, "mini");
                    break;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    strcat(conjugatedVerb, "untur");
                    break;
                }
        }
    }
    return conjugatedVerb;
}

#endif