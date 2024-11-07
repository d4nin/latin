#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "declension.h"

struct adjectives {
    char *noun;
    int type;
    enum Gender gender;
    enum Number number;
    enum Case casus;
};

int getGenderOfAdjective(char *noun) {
    enum Gender gender;
    int length = strlen(noun);

    char lastOne[2];
    lastOne[1] = '\0';
    for (int i = 0; i < 1; i++)
        lastOne[i] = noun[length - 1 + i];
    if (strcmp(lastOne, "a") == 0) {
        gender = FEMININUM;
        return gender;
    }

    char lastTwo[3];
    lastTwo[2] = '\0';
    for (int i = 0; i < 2; i++) 
        lastTwo[i] = noun[length - 2 + i];
    if (strcmp(lastTwo, "us") == 0 || strcmp(lastTwo, "er") == 0
        || strcmp(lastTwo, "ir") == 0) {
        gender = MASCULINUM;
        return gender;
    }
    if (strcmp(lastTwo, "um") == 0) {
        gender = NEUTRUM;
        return gender;
    }
    return -1;
}

char *getStemOfAdjective(struct adjectives adjective, char *noun) {
    char *stem = (char *)malloc((strlen(adjective.noun) + 1) * sizeof(char));
    strcpy(stem, adjective.noun);
    int length = strlen(stem);
    stem[length - 2] = '\0';

    int gender = getGenderOfAdjective(noun);
    
    if (gender == FEMININUM && adjective.type == 1) {
        strcat(stem, "a");
        return stem;    
    }
    if (gender == MASCULINUM && adjective.type == 2) {
        strcat(stem, "us");
        return stem;
    }
    if (gender == NEUTRUM && adjective.type == 2) {
        strcat(stem, "um");
        return stem;
    }
    return "";
}

char *declineAdjectiveFirstDeclension(struct adjectives adjective, char *noun) {
    char *stem = getStemOfAdjective(adjective, noun);
    char *conjugatedAdjective = "";
    int length = strlen(stem);

    if (adjective.number == SINGULAR) {
        switch (adjective.casus) {
            case NOMINATIVE:
            case VOCATIVE:
            case ABLATIVE:
                conjugatedAdjective = stem;
                return stem;
            case GENITIVE:
            case DATIVE:
                conjugatedAdjective = strcat(stem, "e");
                return stem;
            case ACCUSATIVE:
                conjugatedAdjective = strcat(stem, "m");
                return stem;
        }
    }
    if (adjective.number == PLURAL) {
        switch (adjective.casus) {
            case NOMINATIVE:
            case VOCATIVE:
                conjugatedAdjective = strcat(stem, "e");
                return stem;
            case DATIVE:
            case ABLATIVE:
                stem[length - 1] = '\0';
                conjugatedAdjective = strcat(stem, "is");
                return conjugatedAdjective;
            case GENITIVE:
                conjugatedAdjective = strcat(stem, "rum");
                return conjugatedAdjective;  
            case ACCUSATIVE:
                conjugatedAdjective = strcat(stem, "s");
                return conjugatedAdjective; 
        }
    }
    return "";
}

#endif