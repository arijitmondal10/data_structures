#include<stdio.h>

int main(){

    int n;
    int a ,b;
    printf("Enter no of Inputs:");
    scanf("%d",&n);
    printf("enter 1st number:");
    scanf("%d",&a);

    for(int i=2;i<=n;i++){
        printf("Enter number %d:",i);
        scanf("%d",&b);

        if(a>b){
            a=b;
        }
    }
    printf("Smallest no is: %d",a);

    return 0;
}