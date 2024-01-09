#include <stdio.h>
#include "List.h"

struct Node {
    ElementType Element;
    Position    Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

int Find(ElementType X, List L)
{
    Position P;
    
    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    
    return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, Tmp;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) {
        Tmp = P->Next;
        P->Next = Tmp->Next;
        free(Tmp);
    }

    return;
}