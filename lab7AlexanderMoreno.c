//Alexander Moreno
//Lab 7 3-8-2024
//COP3502 0005

#include <stdio.h>

//function to perform selection sort.
void selectionSort(int arr[], int n, int swapCount[]) {
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            //swap elements.
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            //increment swap count.
            swapCount[arr[minIndex]]++;
            swapCount[arr[i]]++;
        }
    }
}

//function to perform bubble sort.
void bubbleSort(int arr[], int n, int swapCount[]) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                //swap elements.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                //increment swap count.
                swapCount[arr[j]]++;
                swapCount[arr[j + 1]]++;
            }
        }
    }
}

int main() {
    //declare arrays.
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2) / sizeof(array2[0]);

    //seperate array to prevent errors.
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n3 = sizeof(array3) / sizeof(array3[0]);

    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n4 = sizeof(array4) / sizeof(array4[0]);

    //arrays to store swap counts.
    int swapCount1[100] = {0};
    int swapCount2[100] = {0};
    int swapCount3[100] = {0};
    int swapCount4[100] = {0};

    //call each sort function.
    bubbleSort(array1, n1, swapCount1);
    bubbleSort(array2, n2, swapCount2);
    selectionSort(array3, n3, swapCount3);
    selectionSort(array4, n4, swapCount4);

    //output results for array1 bubble sort.
    printf("array1 Bubble Sort:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("%d: %d\n", array1[i], swapCount1[array1[i]]);
    }
    int totalSwaps1 = 0;
    for (int i = 0; i < 100; i++)
    {
        totalSwaps1 += swapCount1[i];
    }
    printf("%d\n", totalSwaps1/2);

    //output results for array2 bubble sort.
    printf("array2 Bubble Sort:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("%d: %d\n", array2[i], swapCount2[array2[i]]);
    }
    int totalSwaps2 = 0;
    for (int i = 0; i < 100; i++)
    {
        totalSwaps2 += swapCount2[i];
    }
    printf("%d\n", totalSwaps2/2);

    //output results for array3 selected sort.
    printf("array3 Selected:\n");
    for (int i = 0; i < n1; i++)
    {
        printf("%d: %d\n", array3[i], swapCount3[array3[i]]);
    }
    int totalSwaps3 = 0;
    for (int i = 0; i < 100; i++)
    {
        totalSwaps3 += swapCount3[i];
    }
    printf("%d\n", totalSwaps3/2);

    //output results for array4 selected sort.
    printf("array4 Selected:\n");
    for (int i = 0; i < n1; i++)
    {
        printf("%d: %d\n", array4[i], swapCount4[array4[i]]);
    }
    int totalSwaps4 = 0;
    for (int i = 0; i < 100; i++)
    {
        totalSwaps4 += swapCount4[i];
    }
    printf("%d\n", totalSwaps4/2);

    return 0;
}
