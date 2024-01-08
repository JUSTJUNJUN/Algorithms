#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CAPABILITY_OF_BUCKET    100


typedef struct {
    int key;
    char *value;
} val_bucket;


typedef struct {
    val_bucket *buckets[MAX_CAPABILITY_OF_BUCKET];
} array_hash_table;


/* Hash Function: f(key) = key */
int hash_convert(int key)
{
    return key;
}


/* Create */
array_hash_table *new_array_hash_table(void)
{
    array_hash_table *new = malloc(sizeof(array_hash_table));

    return new;
}


/* Destroy */
void destroy_array_hash_table(array_hash_table *ht_ptr)
{
    for(int i = 0; i < MAX_CAPABILITY_OF_BUCKET; i++) {
        if (ht_ptr->buckets[i] != NULL) {
            free(ht_ptr->buckets[i]->value);
            free(ht_ptr->buckets[i]);
        }
    }

    return;
}


/* Add */
void add_element(array_hash_table *ht, const int key, const char *val)
{
    val_bucket *val_buf = NULL;
    int idx = -1;

    val_buf = malloc(sizeof(val_bucket));
    val_buf->key = key;
    val_buf->value = malloc(strlen(val) + 1);
    strncpy(val_buf->value, val, strlen(val) + 1);

    idx = hash_convert(key);
    ht->buckets[idx] = val_buf;
    
    return;
}


/* Del */
void del_element(array_hash_table *ht, const int key)
{
    int idx = -1;

    idx = hash_convert(key);
    free(ht->buckets[idx]->value);
    free(ht->buckets[idx]);
    ht->buckets[idx] = NULL;

    return;
}


/* Find */
char *find_element(array_hash_table *ht, const int key)
{
    int idx = -1;

    idx = hash_convert(key);

    return ht->buckets[idx]->value;
}


/* Get all key-val */
void get_all_element(array_hash_table *src_ht, array_hash_table *dst_ht)
{
    array_hash_table *tmp_ht = NULL;

    tmp_ht = malloc(sizeof(array_hash_table));

    for (int i = 0; i < MAX_CAPABILITY_OF_BUCKET; i++) {
        if (src_ht->buckets[i] != NULL) {
            add_element(tmp_ht, src_ht->buckets[i]->key, src_ht->buckets[i]->value);
        }
    }

    return;
}


int main(void)
{
    /* trying handle some problems through hash function */

    return 0;
}