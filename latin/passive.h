#ifndef PASSIVE_H
#define PASSIVE_H

#include "includes.h"
#include "conjugation.h"

char *conjugateVerbPassive(struct Conjugation conjugation) {
    char *stem = getStemOfVerb(conjugation);
    char *conjugatedVerb = (char *)malloc((strlen(stem) + 1) * sizeof(char));
    strcpy(conjugatedVerb, stem);

    if (isFirstConjugation(conjugation) || isSecondConjugation(conjugation)) {
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

bool isVerbPassiveVoice(char *verb) {
    char *copyVerb = (char *)malloc((strlen(verb) + 1) * sizeof(char));
    strcpy(copyVerb, verb);
    int length = strlen(copyVerb);

    char lastTwo[3];
    lastTwo[2] = '\0';
    
    for (int i = 0; i < 2; i++) 
        lastTwo[i] = copyVerb[length - 2 + i];

    if (strcmp(lastTwo, "or") == 0) {
        free(copyVerb);
        return true;
    }
    
    char lastThree[4];
    lastThree[3] = '\0';

    for (int i = 0; i < 3; i++)
        lastThree[i] = copyVerb[length - 3 + i];

    if (   strcmp(lastThree, "ris") == 0 || strcmp(lastThree, "tur") == 0
        || strcmp(lastThree, "mur") == 0) {
        free(copyVerb);
        return true;
    }

    char lastFour[5];
    lastFour[4] = '\0';

    for (int i = 0; i < 4; i++)
        lastFour[i] = copyVerb[length - 4 + i];

    if (   strcmp(lastFour, "mini") == 0 || strcmp(lastFour, "ntur") == 0
        || strcmp(lastFour, "eris") == 0 || strcmp(lastFour, "itur") == 0
        || strcmp(lastFour, "imur") == 0) {
        free(copyVerb);
        return true;
    }

    char lastFive[6];
    lastFive[5] = '\0';

    for (int i = 0; i < 5; i++) 
        lastFive[i] = copyVerb[length - 5 + i];

    if (strcmp(lastFive, "imini") == 0 || strcmp(lastFive, "untur") == 0) {
        free(copyVerb);
        return true;
    }
    
    return false;
}

#endif