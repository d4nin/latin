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

enum Case {
    NOMINATIVE,
    GENETIVE,
    DATIVE,
    ACCUSATIVE,
    VOCATIVE,
    ABLATIVE
};

struct Declension {
    char *noun;
    enum declensionType type;
    enum Gender gender;
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