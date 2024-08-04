

#include <stdio.h>


#define NOT_IN_ARRAY    -1


/****************** Search someone element ******************/


/**
 * Time: O(logn)
 * Memory: O(1)
 * Pattern: [left, right]
 */
static int 
search_num_in_array_use_close_interval(int nums[], const len ,const int target)
{
    int left = 0;
    int right = len - 1;
    int middle = 0;

    while (right >= left) {

        middle = left + ((right - left) / 2);

        if (nums[middle] < target) {
            left = middle + 1;

        } else if (nums[middle] > target) {
            right = middle - 1;

        } else {
            return middle;
        }
    }

    return NOT_IN_ARRAY;
}


/**
 * Time: O(logn)
 * Memory: O(1)
 * Pattern: [left, right)
 */
static int
search_num_in_array_use_open_interval(int nums[], const len ,const int target)
{
    int left = 0;
    int right = len - 1;
    int middle = 0;

    while (right > left) {
        
        middle = left + ((right - left) / 2);
        
        if (nums[middle] < target) {
            left = middle + 1;

        } else if (nums[middle] > target) {
            right = middle;

        } else {
            return middle;
        }
    }
    
    return NOT_IN_ARRAY;
}


/****************** Delete indicated elements ******************/


/**
 * Time: O(n)
 * Memory: O(1)
 * Pattern: Fast-slow pointer
 */
static int
delete_target_num_in_array(int nums[], const len, const int target)
{
    int slow_p, fast_p = 0;

    for (fast_p = 0; fast_p < len; fast_p++) {
        if (nums[fast_p] != target) {
            nums[slow_p] = nums[fast_p];
            slow_p++;
        }
    }

    return slow_p;
}


/****************** Square of ordered array ******************/


static int *
caculate_square_of_ordered_array(int nums[], const int len)
{
    int *new = malloc(sizeof(int) * len);
    int update = len -1;
    int left = 0;
    int right = len - 1;

    while (right >= left) {
        if (nums[right] * nums[right] > nums[left] * nums[left]) {
            new[update] = nums[right] * nums[right];
            update--;
            right--;
        } else {
            new[update] = nums[left] * nums[left];
            update--;
            left++;
        }
    }

    return new;
}


/****************** Min sub array len of indicated sum ******************/


static int
caculate_min_length_of_array_in_sum(int nums[], const int len, const int target_sum)
{
    int res = __INT_MAX__;
    int window = 0;
    int i, j, sum = 0;

    for (j = 0; j < len - 1; j++) {
        sum += nums[j];
        while (sum >= target_sum) {
            window = j - i + 1;
            res = res < window ? res : window;
            sum -= nums[i];
            i++;
        }
    }

    return res == __INT_MAX__ ? 0 : res;
}


/****************** Main ******************/


int main(void)
{
    return 0;
}