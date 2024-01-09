/**
 * @author xuehaojun
 * @brief 原地删除在一个有序数组nums中重复出现的元素，使每个元素只出现一次，并返回新数组的新长度
 * @date 2022-11-14
 */
/* 双指针算法，可将方法的空间复杂度为O(1) */

#include <stdio.h>
#include <stdlib.h>

int delete_duplicate_element_in_array(int nums[], int len)
{
    if (len < 2) return len;

    int i = 0, j = 0;

    for (j = 1; j < len; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}
