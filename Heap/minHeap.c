#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "heap.h"

void heapifyDown(Heap * heap,int idx){
    int smallest = idx;
    int leftChild =LeftChildIndex(idx);
    int rightChild =RightChildIndex(idx);
    if(smallest < heap->size && heap->arr[smallest] > heap->arr[leftChild]){
        smallest = leftChild;
    }
    if(smallest < heap->size && heap->arr[smallest] > heap->arr[rightChild]){
        smallest =  rightChild;
    }
    if(smallest != idx){
         int temp = heap->arr[smallest];
        heap->arr[smallest] = heap->arr[idx];
        heap->arr[idx] = temp;

        heapifyDown(heap,smallest);
    }
}

int main(){
    int arr[10] = {10,24,36,19,37,2,3,18,98,27};
    Heap * heap = heapify(arr,10);

    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
}