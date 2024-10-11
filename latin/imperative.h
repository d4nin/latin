#include "conjugation.h"

char *imperativeFirst(struct Conjugation conjugation) {
    char *base = getBaseOfVerb(conjugation);

    char *imperativeSingular;
    char *imperativePlural; 
    if (conjugation.Person == SECOND_PERSON) {
        switch (conjugation.type) {
            case FIRST:
            case SECOND:
            case FOURTH:
                if (conjugation.Number == SINGULAR) {
                    imperativeSingular = base;
                    return imperativeSingular;
                } 
                if (conjugation.Number == PLURAL) {
                    imperativePlural = strcat(base, "te");
                    return imperativePlural;
                }
            case THIRD:
                if (conjugation.Number == SINGULAR) {
                    imperativeSingular = strcat(base, "e");
                    return imperativeSingular;
                }
                if (conjugation.Number == PLURAL) {
                    imperativePlural = strcat(base, "ite");
                    return imperativePlural;
                }
        }
    } else return "verb is not in 2nd person.";
}
