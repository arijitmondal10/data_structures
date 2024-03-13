#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define parent(i) (i-1)/2
#define LeftChildIndex(i) (2*i+1)
#define RightChildIndex(i) (2*i+2)
#define LastIntermediateNode(size) (size-2)/2

typedef struct Heap{
    int *arr;
    int size;
}Heap;

Heap * createHeap(){
    Heap * heap = (Heap *)malloc(sizeof(Heap));
    heap->arr = NULL;
    heap->size = 0;
    return heap;
}

int isEmpty(Heap * heap){
    if(heap->size ==0){
        return 1;
    }
    else{
        return 0;
    }
}

Heap * heapifyUp(Heap * heap,int index){
    while(index > 0 && heap->arr[index] > heap->arr[parent(index)]){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[parent(index)];
        heap->arr[parent(index)] = temp;
        index = parent(index);
    }
}

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

void insert(Heap * heap,int value){
    heap->size ++;
    heap->arr = (int *)realloc(heap->arr,heap->size*sizeof(int));
    heap->arr[heap->size-1] = value;
    heapifyUp(heap,heap->size-1);
}

void delete(Heap * heap,int index){
    if(isEmpty(heap) || index<0 || index >heap->size){
        printf("Invalid");
    }
    else{
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[heap->size-1];
        heap->arr[heap->size-1] = temp;
        heap->size--;

        heapifyDown(heap,index);
    }

}


int main(){
    int arr[10]={23,10,31,18,12,9,25,29,41,5};
    Heap * heap = heapify(arr,10);
    insert(heap,1);
    delete(heap,2);
    for(int i =0;i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
}