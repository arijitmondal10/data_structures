#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "heap.h"


void heapifyDown(Heap * heap,int index){
    int largest = index;
    int leftChild = LeftChildIndex(index);
    int rightChild = RightChildIndex(index);

    if(leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]){
        largest = leftChild;
    }
    if(rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]){
        largest = rightChild;
    }
    if(largest != index){
        int temp = heap->arr[largest];
        heap->arr[largest] = heap->arr[index];
        heap->arr[index] = temp;

        heapifyDown(heap,largest);
    }
    return;
}

int main(){
    int arr[10]={23,10,31,18,12,9,25,29,41,5};
    Heap * heap = heapify(arr,10);
    for(int i =0;i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
}