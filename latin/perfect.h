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

#endif