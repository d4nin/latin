#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "declension.h"

struct adjectives {
    char *noun;
    int type;
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

#endif