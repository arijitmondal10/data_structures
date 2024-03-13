#include<stdio.h>

int main(){

    int n;
    int num ,max,min;
    printf("Enter no of Inputs:");
    scanf("%d",&n);
    printf("enter 1st number:");
    scanf("%d",&min);

    max = min;

    for(int i=2;i<=n;i++){
        printf("Enter number %d:",i);
        scanf("%d",&num);

        if(max<num){
            max = num;
        }
        if(min>num){
            min= num;
        }
    }
    printf("Largest: %d \n",max);
    printf("Smallest:%d",min);

    return 0;
}