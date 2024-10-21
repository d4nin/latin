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

#endif