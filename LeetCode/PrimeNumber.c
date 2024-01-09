/**
 * @author xuehaojun
 * @brief 统计n以内的素数个数，素数指的是只能被1和自身整除的自然数，0、1除外
 * @date 2022-11-09
 */

#include <stdio.h>
#include <stdlib.h>

/* 普通循环算法 */
int is_prime(int x)
{
    /* 只要判断小于根号n即可，由于合数循环乘积是对称的 */
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}
int count_prime_numbers(int n)
{
    int count = 0;

    for (int i = 2; i < n; i++) {
        count += is_prime(i) ? 1 : 0;
    }

    return count;
}

/* 埃氏筛选算法 */
int era_count_prime_numbers(int n)
{
    int tag[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        tag[i] = 0;/* 0表示素数，1表示合数 */
    }

    for (int i = 2; i < n; i++) {
        if (!tag[i]) {
            count++;
            /* 可优化为 i*i，但是需要警惕大数越界的问题 */
            for (int j = i * i; j < n; j += i) {
                tag[i] = 1;
            }
            /*
            for (int j = 2 * i; j < n; j += i) {
                tag[i] = 1;
            }
            */
        }
    }

    return count;
}

