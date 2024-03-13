#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "heap.h"

Heap * createHeap(){
    Heap * heap = (Heap *)malloc(sizeof(Heap));
    heap->arr = NULL;
    heap->size = 0;
    return heap;   
}

Heap * heapify(int data[], int size){
    Heap * heap = createHeap();
    heap->arr = (int *)malloc(size*sizeof(int));
    
    for(int i =0;i<size;i++){
        heap->arr[i] = data[i];
    }
    heap->size = size;
    //Heapify down
    for(int i = LastIntermediateNode(size);i>=0;i--){
        heapifyDown(heap,i);
    }
    return heap;
}