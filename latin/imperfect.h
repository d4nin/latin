#ifndef IMPERFECT_H
#define IMPERFECT_H

#include "includes.h"
#include "conjugation.h"

char *conjugateVerbPerfect(struct Conjugation conjugation) {
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

#endif