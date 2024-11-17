#include <stdio.h>
#include "pile.h"

DECLARER_PILE(int)
DECLARER_PILE(float)

IMPLEMENTER_PILE(int)
IMPLEMENTER_PILE(float)

int main()
{
    Pileint_t pileInt;
    pileInt.top = -1;

    empilerint(42, &pileInt);
    empilerint(50, &pileInt);
    empilerint(25, &pileInt);

    printf("[UNSTACK] : %d \n", depilerint(&pileInt));
    printf("[UNSTACK] : %d \n", depilerint(&pileInt));
    printf("[UNSTACK] : %d \n", depilerint(&pileInt));

    estVideint(&pileInt) ? printf("Empty stack. \n") : printf("Stack is not empty. \n");
}