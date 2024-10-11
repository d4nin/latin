#include "includes.h"

enum declensionType {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
};

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

struct Declension {
    char *noun;
    enum declensionType type;
    enum Gender gender;
    enum Number number;
    enum Case casus; 
};

char *getBaseOfNoun(struct Declension declension) {
    char *noun = declension.noun;
    int length = strlen(noun);

    char *copy = (char *)malloc((length + 1) * sizeof(char));
    strcpy(copy, noun);

    switch (declension.type) {
        case FIRST:
            copy[length - 1] = '\0';
            return copy;
    }
}

char *declineNoun(struct Declension declension) {
    char *base = getBaseOfNoun(declension);
    char *declinedNoun;

    switch (declension.type) {
        case FIRST:
            if (declension.gender == NEUTRUM)
                return "noun cannot be of gender neutrum.";
            if (declension.number == SINGULAR) {
                switch (declension.casus) {
                    case NOMINATIVE:
                        declinedNoun = strcat(base, "a");
                        return declinedNoun;
                    case GENITIVE:
                        declinedNoun = strcat(base, "ae");
                        return declinedNoun;
                    case DATIVE:
                        declinedNoun = strcat(base, "ae");
                        return declinedNoun;
                    case ACCUSATIVE:
                        declinedNoun = strcat(base, "am");
                        return declinedNoun;
                    case VOCATIVE:
                        declinedNoun = strcat(base, "a");
                        return declinedNoun;
                    case ABLATIVE:
                        declinedNoun = strcat(base, "a");
                        return declinedNoun;
                }
            }
            if (declension.number == PLURAL) {
                switch (declension.casus) {
                    case NOMINATIVE:
                        declinedNoun = strcat(base, "ae");
                        return declinedNoun;
                    case GENITIVE:
                        declinedNoun = strcat(base, "arum");
                        return declinedNoun;
                    case DATIVE:
                        declinedNoun = strcat(base, "is");
                        return declinedNoun;
                    case ACCUSATIVE:
                        declinedNoun = strcat(base, "as");
                        return declinedNoun;
                    case VOCATIVE:
                        declinedNoun = strcat(base, "ae");
                        return declinedNoun;
                    case ABLATIVE: 
                        declinedNoun = strcat(base, "is");
                        return declinedNoun;
                }  
            }
    }
}