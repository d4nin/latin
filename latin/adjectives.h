#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "declension.h"

struct adjectives {
    char *noun;
    int gender;
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

#endif