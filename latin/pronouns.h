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