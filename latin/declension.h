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
        case SECOND:
            copy[length - 2] = '\0';
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
        case SECOND:
            if (declension.gender == FEMININUM) 
                return "noun cannot be of gender femininum.";
            if (declension.gender == MASCULINUM) {
                char *noun = declension.noun;
                int length = strlen(noun);

                char lastTwo[3];
                lastTwo[2] = '\0';

                for (int i = 0; i < 2; i++) 
                    lastTwo[i] = noun[length - 2 + i];
                
                if (strcmp(lastTwo, "us") == 0) {
                    switch (declension.casus) {
                        case NOMINATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "us");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "i");
                                return declinedNoun;
                            }
                        case GENITIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "i");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "orum");
                                return declinedNoun;
                            }
                        case DATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "o");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "is");
                                return declinedNoun;
                            }
                        case ACCUSATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "um");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "os");
                                return declinedNoun;
                            }
                        case VOCATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "e");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "i");
                                return declinedNoun;
                            }
                        case ABLATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "o");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "is");
                                return declinedNoun;
                            }
                    }
                }
                if (strcmp(lastTwo, "er") == 0) {
                    switch (declension.casus) {
                        case NOMINATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "er");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "ri");
                                return declinedNoun;
                            }
                        case GENITIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "ri");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "rorum");
                                return declinedNoun;
                            }
                        case DATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "ro");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "ris");
                                return declinedNoun;
                            }
                        case ACCUSATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "rum");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "ros");
                                return declinedNoun;
                            }
                        case VOCATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "er");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "ri");
                                return declinedNoun;
                            }
                        case ABLATIVE:
                            if (declension.number == SINGULAR) {
                                declinedNoun = strcat(base, "ro");
                                return declinedNoun;
                            } else {
                                declinedNoun = strcat(base, "ris");
                                return declinedNoun;
                            }
                    }
                }
            }
            if (declension.gender == NEUTRUM) {
                switch (declension.casus) {
                    case NOMINATIVE:
                    case ACCUSATIVE:
                    case VOCATIVE:
                        if (declension.number == SINGULAR) {
                            declinedNoun = strcat(base, "um");
                            return declinedNoun;
                        } else {
                            declinedNoun = strcat(base, "a");
                            return declinedNoun;
                        }
                    case GENITIVE:
                        if (declension.number == SINGULAR) {
                            declinedNoun = strcat(base, "i");
                            return declinedNoun;
                        } else {
                            declinedNoun = strcat(base, "orum");
                            return declinedNoun;
                        }
                    case DATIVE:
                    case ABLATIVE:
                        if (declension.number == SINGULAR) {
                            declinedNoun = strcat(base, "o");
                            return declinedNoun;
                        } else {
                            declinedNoun = strcat(base, "is");
                            return declinedNoun;
                        }
                }
            }
    }
}