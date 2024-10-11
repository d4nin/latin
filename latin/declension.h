#include "includes.h"

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
    char *genitiveEnding;
    enum Gender gender;
    enum Case casus; 
};