#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define parent(i) (i - 1) / 2
#define left_child_index(i) (2 * i + 1)
#define right_child_index(i) (2 * i + 2)
#define last_intermediate_node(size) (size - 2) / 2

typedef struct Heap
{
    int size;
    int *arr;
} Heap;

//creating an empty heap
Heap * createHeap(){
    Heap * heap = (Heap *)malloc(sizeof(Heap));
    heap->arr = NULL;
    heap->size = 0;
    return heap;
}

int isEmpty(Heap * heap){
   if(heap->size ==0)
   {
    return 1;
   }
   else{
    return 0;
   }
}

Heap * heapifyUp(Heap * heap,int index){
      // Swapping the child with its parent until the parent is smaller than the child
    while(index > 0 && heap->arr[index] < heap->arr[parent(index)]){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[parent(index)];
        heap->arr[parent(index)] = temp;
        index = parent(index);
    }
}

void HeapifyDown(Heap *heap, int index)
{
    int smallest = index;
    int leftchild = left_child_index(index);
    int rightchild = right_child_index(index);
    
    if (leftchild < heap->size && heap->arr[leftchild] < heap->arr[smallest])
    {
        smallest = leftchild;
    }
    if(rightchild < heap->size && heap->arr[rightchild] < heap->arr[smallest]){
        smallest = rightchild;
    }
    if(smallest != index){
        int temp = heap->arr[smallest];
        heap->arr[smallest] = heap->arr[index];
        heap->arr[index] = temp;

        HeapifyDown(heap,smallest);
    }
    return;
}

Heap * heapify(int data[], int size)
{
    Heap *heap = createHeap();
    heap->arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        heap->arr[i] = data[i];
    }
    heap->size = size;

    // for last intermediate node
    for (int i = last_intermediate_node(size); i >= 0; i--)
    {
        HeapifyDown(heap, i);
    }
    return heap;
}

void insert(Heap *heap,int value){
    heap->size++;
    heap->arr = (int *)realloc(heap->arr,heap->size*sizeof(int));
    heap->arr[heap->size-1] = value;
    heapifyUp(heap,heap->size-1);
}

void delete(Heap * heap,int index){
    if(isEmpty(heap) || index < 0 || index >heap->size){
        printf("Invalid");
    }
    else{
        //Swapping the index element with the last element of the heap and decresing the size
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[heap->size-1];
        heap->arr[heap->size-1] = temp;
        heap->size--;

        HeapifyDown(heap,index);
    }
}

int main()
{
    int arr[10] = {10,24,36,19,37,2,3,18,98,27};
    Heap * heap = heapify(arr,10);
    insert(heap,100);
    delete(heap,2);

    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
}