/**
 * @author xuehaojun
 * @brief 给定一个长度为n的整数数组height，找出容纳最多水量的容器大小值 
 * @date 2022-11-19
 */

#include <stdio.h>
#include <stdlib.h>

/* 暴力解法，双重循环 */
int maxArea(int* height, int heightSize){
    int *ptr = NULL;
    int maxarea = 0, area = 0;

    for (int i = 0; i < heightSize - 1; ++i) {
        ptr = height + i;
        for (int j = i + 1; j < heightSize; ++j) {
            if (height[j] > height[i]) {
                area = height[i] * (j - i);
            } else {
                area = height[j] * (j - i);
            }
            if (area > maxarea) {
                maxarea = area;
            }
        }
    }

    return maxarea;
}


/* 先指定两端，得到初始面积，将高度小的一端收紧，获得更大的面积值 */
int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1;
    int area = 0, maxarea = 0;

    while (i < j) {
        if (height[j] > height[i]) {
            area = height[i] * (j - i);
            i++;
        } else {
            area = height[j] * (j - i);
            j--;
        }
        if (area > maxarea) maxarea = area;
    }
    
    return maxarea;
}
