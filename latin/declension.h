#include "includes.h"

enum Gender {
    MASCULINUM,
    FEMININUM,
    NEUTRUM
};

enum Number {
    SINGULAR,
    PLURAL
};

enum Case {
    NOMINATIVE,
    GENITIVE,
    DATIVE,
    ACCUSATIVE,
    VOCATIVE,
    ABLATIVE
};

struct declensionFirst {
    char *noun;
    enum Gender gender;
    enum Number number;
    enum Case casus; 
};

char *getStemOfNounFirstDeclension(struct declensionFirst first) {
    char *noun = first.noun;
    int length = strlen(noun);

    char *copy = (char *)malloc((length + 1) * sizeof(char));
    strcpy(copy, noun);

    copy[length - 1] = '\0';
    return copy;
}