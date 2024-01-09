#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* method1 is O(N^3) */
int method1(int interger[], int num)
{
    int tmp = 0, max_sum = 0;
    int i = 0, j = 0, k = 0;
    
    for (i = 0; i < num; i++) {
        for (j = i; j < num; j++) {
            tmp = 0;
            for (k = i; k <= j; k++) {
                tmp += interger[k];
            }
            if (tmp > max_sum) {
                max_sum = tmp;
            }
        }
    }

    return max_sum;
}

/* method2 is O(N^2) */
int method2(int interger[], int num)
{
    int tmp = 0, max_sum = 0;
    int i = 0, j = 0;
    
    for (i = 0; i < num; i++) {
        tmp = 0;
        for (j = i; j < num; j++) {
            tmp += interger[j];
            if (tmp > max_sum) {
                max_sum = tmp;
            }
        }
    }

    return 0;
}

/* method3 is O(NlogN), recursion */
int method3(int interger[], int num)
{


    return 0;
}

/* method3 is O(N) */
int method4(int interger[], int num)
{
    int tmp = 0, max_sum = 0;
    int i = 0;

    tmp = max_sum = 0;
    for (i = 0; i < num; i++) {
        tmp = interger[i];
        if (tmp > max_sum) {
            max_sum = tmp;
        } else if (tmp < 0) {
            tmp = 0;
        }
    }

    return 0;
}

int main(void)
{
    return 0;
}