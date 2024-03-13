#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Queue* ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue * ptr){
    if(ptr->f==ptr->r){
        return 1;
    }
     return 0;
}

void enQueue(struct Queue * ptr,int data){
    if(isFull(ptr)){
        printf("Queue Overflow...");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]= data;
    }
}

int deQueue(struct Queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty.");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enQueue(&q,9);
    enQueue(&q,10);

    printf("%d \n",deQueue(&q));
    printf("%d \n",deQueue(&q));
    
    if(isEmpty(&q)){
        printf("Empty \n");
    }
}
