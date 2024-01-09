#include <stdio.h>

#define MaxSize 100

typedef int ElementType;
typedef struct SNode *Stack;

struct SNode {
    ElementType Data[MaxSize];
    int Top;
};

