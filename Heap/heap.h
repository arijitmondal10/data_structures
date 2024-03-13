#include<stdbool.h>

#define parent(i) (i-1)/2
#define LeftChildIndex(i) (2*i+1)
#define RightChildIndex(i) (2*i+2)
#define LastIntermediateNode(size) (size-2)/2

typedef struct Heap{
    int *arr;
    int size;
}Heap;

Heap * createHeap(); // creating a empty heap
void heapifyDown(Heap * heap,int index);

Heap * heapify(int data[], int size);


