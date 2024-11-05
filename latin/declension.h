#ifndef DECLENSION_H
#define DECLENSION_H

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

struct declension {
    char *noun;
    enum Gender gender;
    enum Number number;
    enum Case casus; 
};

struct declensionSecond {
    char *noun;
    enum Gender gender;
    enum Number number;
    enum Case casus;
    int retension;
};

struct declensionThird {
    char *noun;
    enum Gender gender;
    enum Number number;
    enum Case casus;
    char *genitiveEnding;
    int retension;
};

bool isNounFirstDeclension(struct declension first) {
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

bool isNounSecondDeclension(struct declensionSecond second) {
    char *noun = second.noun;
    int length = strlen(noun);

    char lastTwo[3];
    lastTwo[2] = '\0';

    for (int i = 0; i < 2; i++)
        lastTwo[i] = noun[length - 2 + i];
    if (second.gender == FEMININUM)
        return false;
    if (strcmp(lastTwo, "us") == 0 && second.gender == MASCULINUM)
        return true;
    if (strcmp(lastTwo, "er") == 0 && second.gender == MASCULINUM)
        return true;
    if (strcmp(lastTwo, "ir") == 0 && second.gender == MASCULINUM)
        return true;
    if (strcmp(lastTwo, "um") == 0 && second.gender == NEUTRUM)
        return true;
    return false;
}

bool isNounThirdDeclension(struct declensionSecond third) {
    // what the fuck?
}

bool isNounFourthDeclension(struct declension fourth) {
    char *noun = fourth.noun;
    int length = strlen(noun);

    char lastTwo[3];
    char lastOne[2];

    lastTwo[2] = '\0';
    lastOne[1] = '\0';

    for (int i = 0; i < 2; i++) 
        lastTwo[i] = noun[length - 2 + i];
    for (int i = 0; i < 1; i++) 
        lastOne[i] = noun[length - 1 + i];
    
    if (strcmp(lastOne, "u") == 0 && fourth.gender == NEUTRUM)
        return true;
    if (strcmp(lastTwo, "us") == 0 && (fourth.gender == FEMININUM || fourth.gender == MASCULINUM))
        return true;
    
    return false;
}

bool isNounFifthDeclension(struct declension fifth) {
    char *noun = fifth.noun;
    int length = strlen(noun);

    char lastTwo[3];
    lastTwo[2] = '\0';

    for (int i = 0; i < 2; i++) 
        lastTwo[i] = noun[length - 2 + i];
    if (strcmp(noun, "dies") == 0 && fifth.gender == FEMININUM)
        return false;
    if (strcmp(lastTwo, "es") == 0 && fifth.gender == FEMININUM)
        return true;
    return false;
}

char *getStemOfNounFirstDeclension(struct declension first) {
    if (isNounFirstDeclension(first)) {
        char *noun = first.noun;
        int length = strlen(noun);

        char *copy = (char *)malloc((length + 1) * sizeof(char));
        strcpy(copy, noun);

        copy[length - 1] = '\0';
        return copy;
    } else {
        char *error = (char *)malloc((strlen(first.noun) + 30) * sizeof(char));
        sprintf(error, "%s is not of first declension.", first.noun); 
        return error;
    };
}

char *getStemOfNounSecondDeclension(struct declensionSecond second) {
    if (isNounSecondDeclension(second)) {
        char *noun = second.noun;
        int length = strlen(noun);

        char *copy = (char *)malloc((length + 1) * sizeof(char));
        strcpy(copy, noun);

        if (second.retension == 0 || strcmp(noun, "vir") == 0)
            return copy;
        copy[length - 2] = '\0';
        return copy;
    } else {
        char *error = (char *)malloc((strlen(second.noun) + 50) * sizeof(char));
        sprintf(error, "%s is not of second declension.", second.noun);
        return error;
    }
}

char *getStemOfNounThirdDeclension(struct declensionThird third) {
    char *noun = third.noun;
    int length = strlen(noun);

    char *copy = (char *)malloc((length + 1) * sizeof(char));
    strcpy(copy, noun);

    if (third.retension == 0) {
        copy[length - 1] = '\0';
        return copy;
    }
    
    if (third.retension == 1) {
        copy[length - 2] = '\0';
        return copy;
    }
}

char *getStemOfNounFourthDeclension(struct declension fourth) {
    if (isNounFourthDeclension(fourth)) {
        char *noun = fourth.noun;
        int length = strlen(noun);

        char *copy = (char *)malloc((length + 1) * sizeof(char));
        strcpy(copy, noun);

        if (fourth.gender == NEUTRUM)  {
            copy[length - 1] = '\0';
            return copy;
        }
        if (fourth.gender == MASCULINUM || fourth.gender == FEMININUM) {
            copy[length - 2] = '\0';
            return copy;
        }
    } else {
        char *error = (char *)malloc((strlen(fourth.noun) + 50) * sizeof(char));
        sprintf(error, "%s is not of fourth declension.", fourth.noun);
        return error;
    }
}

char *getStemOfNounFifthDeclension(struct declension fifth) {
    if (isNounFifthDeclension(fifth)) {
        char *noun = fifth.noun;
        int length = strlen(noun);

        char *copy = (char *)malloc((length + 1) * sizeof(char));
        strcpy(copy, noun);

        copy[length - 2] = '\0';
        return copy;
    } else {
        char *error = (char *)malloc((strlen(fifth.noun) + 50) * sizeof(char));
        sprintf(error, "%s is not of fifth declension.", fifth.noun);
        return error;
    }
}

char *declineNounFirstDeclension(struct declension first) {
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
        char *error = (char *)malloc((strlen(first.noun) + 30) * sizeof(char));
        sprintf(error, "%s is not of first declension.", first.noun); 
        return error;
    }
}

char *declineNounSecondDeclension(struct declensionSecond second) {
    char *stem = getStemOfNounSecondDeclension(second);
    char *declinedNoun;

    if (isNounSecondDeclension(second)) {
        char *noun = second.noun;
        int length = strlen(noun);

        char lastTwo[3];
        lastTwo[2] = '\0';

        for (int i = 0; i < 2; i++) 
            lastTwo[i] = noun[length - 2 + i];

        if ((second.retension == 0 || strcmp(noun, "vir") == 0) && second.number == SINGULAR) {
            switch (second.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = stem;
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "o");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "i");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "um");
                    return declinedNoun;
            }
        } 
        if (((second.retension == 0 || strcmp(noun, "vir") == 0) && second.number == PLURAL)
            || (strcmp(lastTwo, "us") == 0 && second.number == PLURAL)) {
            switch (second.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "i");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "is");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "orum");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "os");
                    return declinedNoun;
            }
        }
        if (strcmp(lastTwo, "us") == 0 && second.number == SINGULAR) {
            switch (second.casus) {
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "o");
                    return declinedNoun;
                case NOMINATIVE:
                    declinedNoun = strcat(stem, "us");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "i");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "um");
                    return declinedNoun;
                case VOCATIVE:
                    declinedNoun = strcat(stem, "e");
                    return declinedNoun;
            }
        }
        if (strcmp(lastTwo, "er") == 0 && second.number == SINGULAR) {
            switch (second.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "er");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "ro");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "ri");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "rum");
                    return declinedNoun;
            }
        }
        if (strcmp(lastTwo, "er") == 0 && second.number == PLURAL) {
            switch (second.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "ri");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "ris");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "rorum");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "ros");
                    return declinedNoun;
            }
        }
        if (strcmp(lastTwo, "um") == 0 && second.number == SINGULAR) {
            switch (second.casus) {
                case NOMINATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "um");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "o");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "i");
                    return declinedNoun;
            }
        }
        if (strcmp(lastTwo, "um") == 0 && second.number == PLURAL) {
            switch (second.casus) {
                case NOMINATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "a");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "is");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "orum");
                    return declinedNoun;
            }
        }
    } else {
        char *error = (char *)malloc((strlen(second.noun) + 50) * sizeof(char));
        sprintf(error, "%s is not of second declension.", second.noun);
        return error;
    }
}

char *declineNounThirdDeclension(struct declensionThird third) {
    char *stem = getStemOfNounThirdDeclension(third);
    char *declinedNoun;

    char *stemGenitiveCaseCat = strcat(stem, third.genitiveEnding);
    int length = strlen(stemGenitiveCaseCat);

    char *stemGenitiveCase = (char *)malloc((length + 1) * sizeof(char));
    strcpy(stemGenitiveCase, stemGenitiveCaseCat);
    stemGenitiveCase[length - 2] = '\0';

    if (third.number == SINGULAR
        && (third.gender == MASCULINUM || third.gender == FEMININUM)) {
        switch (third.casus) {
            case NOMINATIVE:
            case VOCATIVE:
                declinedNoun = third.noun;
                return declinedNoun;
            case GENITIVE:
                declinedNoun = stemGenitiveCaseCat;
                return declinedNoun;
            case DATIVE:
                declinedNoun = strcat(stemGenitiveCase, "i");
                return declinedNoun;
            case ACCUSATIVE:
                declinedNoun = strcat(stemGenitiveCase, "em");
                return declinedNoun;
            case ABLATIVE:
                declinedNoun = strcat(stemGenitiveCase, "e");
                return declinedNoun;
        }
    }
    if (third.number == PLURAL
        && (third.gender == FEMININUM || third.gender == MASCULINUM)) {
        switch (third.casus) {
            case NOMINATIVE:
            case ACCUSATIVE:
            case VOCATIVE:
                declinedNoun = strcat(stemGenitiveCase, "es");
                return declinedNoun;
            case DATIVE:
            case ABLATIVE:
                declinedNoun = strcat(stemGenitiveCase, "ibus");
                return declinedNoun;
            case GENITIVE:
                declinedNoun = strcat(stemGenitiveCase, "um");
                return declinedNoun;
        }
    }
    if (third.number == SINGULAR && third.gender == NEUTRUM) {
        switch(third.casus) {
            case NOMINATIVE:
            case ACCUSATIVE:
            case VOCATIVE:
                declinedNoun = third.noun;
                return declinedNoun;
            case GENITIVE:
                declinedNoun = stemGenitiveCaseCat;
                return declinedNoun;
            case DATIVE:
                declinedNoun = strcat(stemGenitiveCase, "i");
                return declinedNoun;
            case ABLATIVE:
                declinedNoun = strcat(stemGenitiveCase, "e");
                return declinedNoun;
        }
    }
    if (third.number == PLURAL && third.gender == NEUTRUM) {
        switch (third.casus) {
            case NOMINATIVE:
            case ACCUSATIVE:
            case VOCATIVE:
                declinedNoun = strcat(stemGenitiveCase, "a");
                return declinedNoun;
            case DATIVE:
            case ABLATIVE:
                declinedNoun = strcat(stemGenitiveCase, "ibus");
                return declinedNoun;
            case GENITIVE:
                declinedNoun = strcat(stemGenitiveCase, "um");
                return declinedNoun;
        }
    }
}

char *declineNounFourthDeclension(struct declension fourth) {
    char *stem = getStemOfNounFourthDeclension(fourth);
    char *declinedNoun;

    if (isNounFourthDeclension(fourth)) {
        if (fourth.gender == NEUTRUM && fourth.number == SINGULAR) {
            switch (fourth.casus) {
                case NOMINATIVE:
                case DATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "u");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "us");
                    return declinedNoun;
            }
        }
        if (fourth.gender == NEUTRUM && fourth.number == PLURAL) {
            switch (fourth.casus) {
                case NOMINATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "ua");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "ibus");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "uum");
                    return declinedNoun;
            }
        }
        if ((fourth.gender == FEMININUM || fourth.gender == MASCULINUM) && fourth.number == SINGULAR) {
            switch (fourth.casus) {
                case NOMINATIVE:
                case GENITIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "us");
                    return declinedNoun;
                case DATIVE:
                    declinedNoun = strcat(stem, "ui");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "um");
                    return declinedNoun;
                case ABLATIVE:
                    declinedNoun = strcat(stem, "u");
                    return declinedNoun;
            }
        }
        if ((fourth.gender == FEMININUM || fourth.gender == MASCULINUM) && fourth.number == PLURAL) {
            switch (fourth.casus) {
                case NOMINATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "us");
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "ibus");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "uum");
                    return declinedNoun;
            }
        }
    }
}

char *declineNounFifthDeclension(struct declension fifth) {
    char *stem = getStemOfNounFifthDeclension(fifth);
    char *declinedNoun;

    if (isNounFifthDeclension(fifth)) {
        if (fifth.number == SINGULAR) {
            switch (fifth.casus) {
                case NOMINATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "es");
                    return declinedNoun;
                case GENITIVE:
                case DATIVE:
                    declinedNoun = strcat(stem, "ei");
                    return declinedNoun;
                case ACCUSATIVE:
                    declinedNoun = strcat(stem, "em");
                    return declinedNoun;
                case ABLATIVE:
                    declinedNoun = strcat(stem, "e");
                    return declinedNoun;
            }
        }
        if (fifth.number == PLURAL) {
            switch (fifth.casus) {
                case NOMINATIVE:
                case ACCUSATIVE:
                case VOCATIVE:
                    declinedNoun = strcat(stem, "es");;
                    return declinedNoun;
                case DATIVE:
                case ABLATIVE:
                    declinedNoun = strcat(stem, "ebus");
                    return declinedNoun;
                case GENITIVE:
                    declinedNoun = strcat(stem, "erum");
                    return declinedNoun;
            }
        }
    }
}

bool checkNounFirstDeclension(char *noun) {
    char lastOne[2];
    lastOne[1] = '\0';
    int length = strlen(noun);

    for (int i = 0; i < 1; i++)
        lastOne[i] = noun[length - 1 + i];
    
    if (strcmp(lastOne, "a") == 0)
        return true;
    return false;
}

bool checkNounSecondDeclension(char *noun) {
    char lastTwo[3];
    lastTwo[2] = '\0';
    int length = strlen(noun);

    for (int i = 0; i < 2; i++) 
        lastTwo[i] = noun[length - 2 + i];
    
    if (strcmp(lastTwo, "us") == 0 || strcmp(lastTwo, "er") == 0 ||
        strcmp(lastTwo, "ir") == 0 || strcmp(lastTwo, "um") == 0) 
            return true;
    return false;
}

#endif