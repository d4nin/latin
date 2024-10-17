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