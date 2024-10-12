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

bool isNounFirstDeclension(struct declensionFirst first) {
    char *noun = first.noun;
    int length = strlen(noun);

    char lastOne[2];
    lastOne[1] = '\0';

    for(int i = 0; i < 1; i++)
        lastOne[i] = noun[length - 1 + i];
    
    if ((strcmp(lastOne, "a") == 0) && (first.gender == FEMININUM || first.gender == MASCULINUM))
        return true;
    else return false;
}

char *declineNounFirstDeclension(struct declensionFirst first) {
    char *stem = getStemOfNounFirstDeclension(first);
    char *declinedNoun;

    if (isNounFirstDeclension(first)) {
        if (first.number == SINGULAR) {
            switch (first.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "a");
                    return declinedNoun;
                case GENITIVE:
                case DATIVE:
                    declinedNoun = strcat(stem, "ae");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "am");
                    return declinedNoun;
            }
        }
        if (first.number == PLURAL) {
            switch (first.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "ae");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "is");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "arum");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "as");
            }
        }
    } else {
        return strcat(first.noun, " is not of first declension.");
    }
}