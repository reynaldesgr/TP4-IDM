#ifndef PILE_H
#define PILE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 50

// Macro pour déclarer une pile pour un type donné
#define DECLARER_PILE(TYPE) \
typedef struct { \
    TYPE pile[TAILLE_MAX]; \
    int top; \
} Pile##TYPE##_t; \
\
void empiler##TYPE(TYPE valeur, Pile##TYPE##_t* this); \
TYPE depiler##TYPE(Pile##TYPE##_t* this); \
bool estVide##TYPE(Pile##TYPE##_t* this);

#define IMPLEMENTER_PILE(TYPE) \
void empiler##TYPE(TYPE valeur, Pile##TYPE##_t* this) { \
    if (this->top >= TAILLE_MAX - 1) { \
        exit(EXIT_FAILURE); \
    } \
    this->pile[++(this->top)] = valeur; \
} \
\
TYPE depiler##TYPE(Pile##TYPE##_t* this) { \
    if (this->top < 0) { \
        exit(EXIT_FAILURE); \
    } \
    return this->pile[(this->top)--]; \
} \
\
bool estVide##TYPE(Pile##TYPE##_t* this) { \
    return this->top == -1; \
}

#endif // PILE_H
