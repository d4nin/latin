#ifndef IMPERATIVE_H
#define IMPERATIVE_H

#include "conjugation.h"

char *imperativeFirst(struct Conjugation conjugation) {
    char *base = getStemOfVerb(conjugation);

    char *imperativeSingular;
    char *imperativePlural; 
    if (conjugation.Person == SECOND_PERSON) {
        switch (conjugation.type) {
            case FIRST:
            case SECOND:
            case FOURTH:
                if (conjugation.Number == SINGULAR) {
                    imperativeSingular = base;
                    return imperativeSingular;
                } 
                if (conjugation.Number == PLURAL) {
                    imperativePlural = strcat(base, "te");
                    return imperativePlural;
                }
            case THIRD:
                if (conjugation.Number == SINGULAR) {
                    imperativeSingular = strcat(base, "e");
                    return imperativeSingular;
                }
                if (conjugation.Number == PLURAL) {
                    imperativePlural = strcat(base, "ite");
                    return imperativePlural;
                }
        }
    } else return "";
}

char *imperativeSecond(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);

    char *imperativeSingular;
    char *imperativePlural;
    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == SECOND_PERSON || conjugation.Person == THIRD_PERSON) {
                    imperativeSingular = strcat(stem, "to");
                    return imperativeSingular;
                }
            case PLURAL:
                if (conjugation.Person == SECOND_PERSON) {
                    imperativePlural = strcat(stem, "tote");
                    return imperativePlural;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    imperativePlural = strcat(stem, "nto");
                    return imperativePlural;
                }
        }
    }
    if (isThirdConjugation(conjugation) || isFourthConjugation(conjugation)) {
        switch (conjugation.Number) {
            case SINGULAR:
                if (conjugation.Person == SECOND_PERSON || conjugation.Person == THIRD_PERSON) {
                    imperativeSingular = strcat(stem, "ito");
                    return imperativeSingular;
                }
            case PLURAL:
                if (conjugation.Person == SECOND_PERSON) {
                    imperativePlural = strcat(stem, "itote");
                    return imperativePlural;
                }
                if (conjugation.Person == THIRD_PERSON) {
                    imperativePlural = strcat(stem, "unto");
                    return imperativePlural;
                }
        }
    }
    return "";
}

#endif