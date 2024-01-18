

#include <stdio.h>
#include <string.h>


#define MAX_SIZE    4096


typedef struct max_heap {
    int size;
    int *data;
} MaxHeap;


int
left_of_node(int i)
{
    return (2 * i + 1);
}


int
right_of_node(int i)
{
    return (2 * i + 2);
}


int
parent_of_node(int i)
{
    return (i - 1)/2;
}


int
is_empty(MaxHeap *heap)
{
    return (heap->data == NULL);
}


int
size_of_heap(MaxHeap *heap)
{
    return heap->size;
}


int
peek(MaxHeap *heap)
{
    return heap->data[0];
}


void
swap(MaxHeap *heap, int i, int p)
{
    int tmp = 0;

    tmp = heap->data[i];
    heap->data[i] = heap->data[p];
    heap->data[p] = tmp;

    return;
}


void
sift_up(MaxHeap *heap, int i)
{
    while (1) {
        int p = parent_of_node(i);

        if (p < 0 || heap->data[p] >= heap->data[i]) {
            break;
        }

        swap(heap, i, p);
        i = p;
    }

    return;
}


void
push(MaxHeap *heap, int val)
{
    if (heap->size == MAX_SIZE) {
        return;
    }

    heap->data[heap->size] = val;
    heap->size++;

    sift_up(heap, heap->size);

    return;
}


void
sift_down(MaxHeap *heap, int i)
{
    while (1) {
        int l = left_of_node(i);
        int r = right_of_node(i);
        int max = i;

        if (l < size_of_heap(heap) && heap->data[l] > heap->data[max]) {
            max = l;
        }

        if (r < size_of_heap(heap) && heap->data[r] > heap->data[max]) {
            max = r;
        }

        if (max == i) {
            break;
        }

        swap(heap, i, max);

        i = max;
    }

    return;
}


int pop(MaxHeap *heap)
{
    if (is_empty(heap)) {
        return -1;
    }

    swap(heap, 0, size_of_heap(heap)-1);

    int val = heap->data[size_of_heap(heap) - 1];

    heap->size--;

    return val;
}


int main(int argc, char const *argv[])
{
    return 0;
}