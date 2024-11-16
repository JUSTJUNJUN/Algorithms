

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Find target number in array, range is [i, j] */
int
binary_search1(int *buf, int size, int target)
{
    int ret = -1;/* not exist */
    int i = 0, j = size - 1;
    
    while (i <= j) {
        int m = j - (j - i)/2;
        if (target < buf[m]) {
            j = m - 1;
        } else if (target > buf[m]) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return ret;
}


/* Find target number in array, range is [i, j) */
int
binary_search2(int *buf, int size, int target)
{
    int ret = -1;/* not exist */
    int i = 0, j = size - 1;
    
    while (i <= j) {
        int m = j - (j - i)/2;
        if (target < buf[m]) {
            j = m;
        } else if (target > buf[m]) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return ret;
}


/* Find target number in array, range is (i, j] */
int
binary_search3(int *buf, int size, int target)
{
    int ret = -1;/* not exist */
    int i = 0, j = size - 1;
    
    while (i <= j) {
        int m = j - (j - i)/2;
        if (target < buf[m]) {
            j = m + 1;
        } else if (target > buf[m]) {
            i = m;
        } else {
            return m;
        }
    }

    return ret;
}


/* Find target insert location, exist only one same number in array */
int
insert_number_binary_tree(int *buf, int size, int target)
{
    int ret = -1;/* not exist */
    int i = 0, j = size - 1;
    
    while (i <= j) {
        int m = j - (j - i)/2;
        if (target < buf[m]) {
            j = m - 1;
        } else if (target > buf[m]) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return (i + 1);
}


/* Find target insert location, exist some equal numbers in array */
int
insert_number_binary_tree2(int *buf, int size, int target)
{
    int ret = -1;/* not exist */
    int i = 0, j = size - 1;
    
    while (i <= j) {
        int m = j - (j - i)/2;
        if (target < buf[m]) {
            j = m - 1;
        } else if (target > buf[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    return (i + 1);
}


/* Find target left, target may not exist */
int
find_target_bound_in_binary_tree(int *buf, int size, int target)
{
    int i = insert_number_binary_tree2(buf, size, target);

    if (i == size || buf[i] != target) {
        return -1;
    }

    return i;
}


int main(void)
{
    /* trying handle some problems through hash function */

    return 0;
}