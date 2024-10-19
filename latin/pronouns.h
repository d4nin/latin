#include "includes.h"

enum Person {
    FIRST_PERSON,
    SECOND_PERSON,
    THIRD_PERSON 
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

enum Gender {
    MASCULINUM,
    FEMININUM,
    NEUTRUM
};

struct pronouns {
    enum Person person;
    enum Number number;
    enum Case casus;
    enum Gender gender;
};

struct demonstrativePronouns {
    struct pronouns pronoun;
    char *demonstrativePronoun;
};

char *getPersonalPronoun(struct pronouns pronoun) {
    char *personalPronoun;
    if (pronoun.casus == VOCATIVE)
        return "";
    if (pronoun.person == FIRST_PERSON && pronoun.number == SINGULAR) {
        switch (pronoun.casus) {
            case ACCUSATIVE:
            case ABLATIVE:
                personalPronoun = "me";
                return personalPronoun;
            case NOMINATIVE:
                personalPronoun = "ego";
                return personalPronoun;
            case GENITIVE:
                personalPronoun = "mei";
                return personalPronoun;
            case DATIVE:
                personalPronoun = "mihi";
                return personalPronoun;
        }
    }
    if (pronoun.person == FIRST_PERSON && pronoun.number == PLURAL) {
        switch (pronoun.casus) {
            case NOMINATIVE:
            case ACCUSATIVE:
                personalPronoun = "nos";
                return personalPronoun;
            case DATIVE:
            case ABLATIVE:
                personalPronoun = "nobis";
                return personalPronoun;
            case GENITIVE:
                personalPronoun = "nostri";
                return personalPronoun;
        }
    }
    if (pronoun.person == SECOND_PERSON && pronoun.number == SINGULAR) {
        switch (pronoun.casus) {
            case ACCUSATIVE:
            case ABLATIVE:
                personalPronoun = "te";
                return personalPronoun;
            case NOMINATIVE:
                personalPronoun = "tu";
                return personalPronoun;
            case GENITIVE:
                personalPronoun = "tui";
                return personalPronoun;
            case DATIVE:
                personalPronoun = "tihi";
                return personalPronoun;
        }
    }
    if (pronoun.person == SECOND_PERSON && pronoun.number == PLURAL) {
        switch (pronoun.casus) {
            case NOMINATIVE:
            case ACCUSATIVE:
                personalPronoun = "vos";
                return personalPronoun;
            case DATIVE:
            case ABLATIVE:
                personalPronoun = "vobis";
                return personalPronoun;
            case GENITIVE:
                personalPronoun = "vostri";
                return personalPronoun;
        }
    }
    if (pronoun.person == THIRD_PERSON && pronoun.number == SINGULAR) {
        switch (pronoun.gender) {
            case MASCULINUM:
                personalPronoun = "is";
                return personalPronoun;
            case FEMININUM:
                personalPronoun = "ea";
                return personalPronoun;
            case NEUTRUM:
                personalPronoun = "id";
        } 
    }
    if (pronoun.person == THIRD_PERSON && pronoun.number == PLURAL) {
        switch (pronoun.gender) {
            case MASCULINUM:
                personalPronoun = "ii";
                return personalPronoun;
            case FEMININUM:
                personalPronoun = "eae";
                return personalPronoun;
            case NEUTRUM:
                personalPronoun = "ea";
                return personalPronoun;
        }
    }
}

char *getReflexivePronoun(struct pronouns pronoun) {
    char *reflexivePronoun;
    if (pronoun.casus == NOMINATIVE || pronoun.casus == VOCATIVE)
        return "";
    switch (pronoun.casus) {
        case ACCUSATIVE:
        case ABLATIVE:
            reflexivePronoun = "se";
            return reflexivePronoun;
        case GENITIVE:
            reflexivePronoun = "sui";
            return reflexivePronoun;
        case DATIVE:
            reflexivePronoun = "sibi";
            return reflexivePronoun;
    }
}

char *getDemonstrativePronoun(struct demonstrativePronouns pronouns) {
    char *demonstrativePronoun;
    if (pronouns.pronoun.casus == VOCATIVE)
        return "";
    if (strcmp(pronouns.demonstrativePronoun, "is, ea, id") == 0 &&
        pronouns.pronoun.number == SINGULAR) {
            switch (pronouns.pronoun.casus) {
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "is";
                        return demonstrativePronoun;
                    } 
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "ea";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "id";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    demonstrativePronoun = "eius";
                    return demonstrativePronoun;
                case DATIVE:
                    demonstrativePronoun = "ei";
                    return demonstrativePronoun;
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "eum";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "eam";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "id";
                        return demonstrativePronoun;
                    }
                case ABLATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM || 
                        pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "eo";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "ea";
                        return demonstrativePronoun;
                    }
            }
    }
    if (strcmp(pronouns.demonstrativePronoun, "is, ea, id") == 0 &&
        pronouns.pronoun.number == PLURAL) {
            switch (pronouns.pronoun.casus) {
                case DATIVE:
                case ABLATIVE:
                    demonstrativePronoun = "eis";
                    return demonstrativePronoun;
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "ii";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "eae";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "ea";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    if (pronouns.pronoun.gender == MASCULINUM ||
                        pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "eorum";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "earum";
                        return demonstrativePronoun;
                    }
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "eos";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "eas";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "ea";
                        return demonstrativePronoun;
                    }
            }
    }
    if (strcmp(pronouns.demonstrativePronoun, "ille, illa, illud") == 0 &&
        pronouns.pronoun.number == SINGULAR) {
            switch (pronouns.pronoun.casus) {
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "ille";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illa";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illud";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    demonstrativePronoun = "illius";
                    return demonstrativePronoun;
                case DATIVE:
                    demonstrativePronoun = "illi";
                    return demonstrativePronoun;
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "illum";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illam";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illud";
                        return demonstrativePronoun;
                    }
                case ABLATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM ||
                        pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illo";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illa";
                        return demonstrativePronoun;
                    }
            }
    }
    if (strcmp(pronouns.demonstrativePronoun, "ille, illa, illud") == 0 &&
        pronouns.pronoun.number == PLURAL) {
            switch (pronouns.pronoun.casus) {
                case DATIVE:
                case ABLATIVE:
                    demonstrativePronoun = "illis";
                    return demonstrativePronoun;
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "illi";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illae";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illa";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    if (pronouns.pronoun.gender == MASCULINUM ||
                        pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illorum";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illarum";
                        return demonstrativePronoun;
                    }
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "illos";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "illas";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "illa";
                        return demonstrativePronoun;
                    }
            }
    }
    if (strcmp(pronouns.demonstrativePronoun, "hic, haec, hoc") == 0 &&
        pronouns.pronoun.number == SINGULAR) {
            switch (pronouns.pronoun.casus) {
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "hic";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "haec";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "hoc";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    demonstrativePronoun = "huius";
                    return demonstrativePronoun;
                case DATIVE:
                    demonstrativePronoun = "huic";
                    return demonstrativePronoun;
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "hunc";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "hanc";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "hoc";
                        return demonstrativePronoun;
                    }
                case ABLATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM ) {
                        demonstrativePronoun = "hec";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "hac";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "hoc";
                        return demonstrativePronoun;
                    }
            }
    }
    if (strcmp(pronouns.demonstrativePronoun, "hic, haec, hoc") == 0 &&
        pronouns.pronoun.number == PLURAL) {
            switch (pronouns.pronoun.casus) {
                case DATIVE:
                case ABLATIVE:
                    demonstrativePronoun = "his";
                    return demonstrativePronoun;
                case NOMINATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "hii";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "heae";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "haec";
                        return demonstrativePronoun;
                    }
                case GENITIVE:
                    if (pronouns.pronoun.gender == MASCULINUM ||
                        pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "horum";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "harum";
                        return demonstrativePronoun;
                    }
                case ACCUSATIVE:
                    if (pronouns.pronoun.gender == MASCULINUM) {
                        demonstrativePronoun = "hos";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == FEMININUM) {
                        demonstrativePronoun = "has";
                        return demonstrativePronoun;
                    }
                    if (pronouns.pronoun.gender == NEUTRUM) {
                        demonstrativePronoun = "haec";
                        return demonstrativePronoun;
                    }
            }
    }
}