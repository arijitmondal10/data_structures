#include <stdio.h>
#include <string.h>
typedef struct student
{
    char name[50];
    float grade;
    int roll_no;
} student;

void sort_by_name(student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].name[0] > s[j + 1].name[0])
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void sort_by_grade(student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].grade < s[j + 1].grade)
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void sort_by_roll_no(student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll_no > s[j + 1].roll_no)
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter student data for student %d:\n", (i + 1));
        printf("name:");
        scanf("%s", s[i].name);
        if (s[i].name[0] < 97)
        {
            s[i].name[0] = s[i].name[0] + 32;
        }
        printf("grade:");
        scanf("%f", &s[i].grade);
        printf("roll no:");
        scanf("%d", &s[i].roll_no);
    }

    sort_by_name(s, n);
    printf("Sorted by name: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", s[i].name);
    }
    printf("\n");

    sort_by_grade(s, n);
    printf("Sorted by grade: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", s[i].name);
    }
    printf("\n");

    sort_by_roll_no(s, n);
    printf("Sorted by roll no: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", s[i].name);
    }
    printf("\n");

    return 0;
}