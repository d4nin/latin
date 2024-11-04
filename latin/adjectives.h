#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "declension.h"

int getAdjectiveGender(char *noun) {    
    enum Gender gender;
    if (checkNounFirstDeclension(noun)) {
        gender = FEMININUM;
        return gender;
    }
}

#endif