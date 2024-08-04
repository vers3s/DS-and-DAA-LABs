#include <stdio.h>
#include <string.h>

struct Student
{
    int mobileNo;
    char name[50];
    int prn;
    char emailId[50];
};

void display(struct Student students[], int count)
{
    printf("ID\t\tName\tphone\temail\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\t%s\n", students[i].prn, students[i].name, students[i].mobileNo, students[i].emailId);
    }
    printf("\n");
}

void bubbleSort(struct Student students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].prn > students[j + 1].prn)
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void insertionSort(struct Student students[], int count)
{
    for (int i = 1; i < count; i++)
    {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].prn > key.prn)
        {
            students[j + 1] = students[j];
            students[j] = key;
            j--;
        }
        students[j + 1] = key;
    }
}

void selectionSort(struct Student students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (students[j].prn < students[minIndex].prn)
            {
                minIndex = j;
            }
        }
        struct Student temp = students[minIndex];
        students[minIndex] = students[i];
        students[i] = temp;
    }
}

int main()
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
	struct Student students[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student %d\n", i + 1);
        printf("PRN: ");
        scanf("%d", &students[i].prn);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("MobileNO: ");
        scanf("%d", &students[i].mobileNo);
        printf("EmailID: ");
        scanf("%s", students[i].emailId);
    }

    printf("\nOriginal student database:\n");
    display(students, n);

    // Sort using Bubble Sort
    bubbleSort(students, n);
    printf("Student database sorted using Bubble Sort:\n");
    display(students, n);

    // Sort using Insertion Sort
    insertionSort(students, n);
    printf("Student database sorted using Insertion Sort:\n");
    display(students, n);

    // Sort using Selection Sort
    selectionSort(students, n);
    printf("Student database sorted using Selection Sort:\n");
    display(students, n);

    return 0;
}