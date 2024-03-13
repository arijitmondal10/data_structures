#include <stdio.h>
#include <string.h>
typedef struct word
{
    char word[50];
} word;

int main()
{
    int n;
    printf("Enter the number of words to be added: ");
    scanf("%d", &n);
    word arr[n];
    printf("Enter words : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].word);
        if (arr[i].word[0] < 97)
        {
            arr[i].word[0] = arr[i].word[0] + 32;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].word[0] > arr[j + 1].word[0])
            {
                word temp;
                strcpy(temp.word, arr[j].word);
                strcpy(arr[j].word, arr[j + 1].word);
                strcpy(arr[j + 1].word, temp.word);
            }
        }
    }

    printf("Sorted words: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", arr[i].word);
    }
    return 0;
}