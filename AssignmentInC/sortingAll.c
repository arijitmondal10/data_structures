/* bubble sort-->

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n-1 ; i++)
    {
        for (int j = 0 ; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
               int  temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            for(int k =0;k<n;k++){
        printf("%d \n",arr[k]);
    }
        }
    }

    printf("The sorted array is :\n");

}

*/

/* selection sort-->

#include<stdio.h>

int main(){
     int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    for(int i =0;i<n-1;i++){
        int small = i;
        for(int j =i+1;j<n;j++){
            if(arr[small]>arr[j]){
               small = j;
            }
        }
         int temp = arr[small];
                arr[small]= arr[i];
                arr[i]= temp;
    }

     printf("The sorted array is :\n");
    for(int i =0;i<n;i++){
        printf("%d \n",arr[i]);
    }
}

*/
/* */
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }

    printf("The sorted array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
}
