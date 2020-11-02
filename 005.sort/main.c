#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    void printfArray(int a[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            printf("%d ", a[i]);
        }
        printf("]\n");
    };

    void InsertSort(int a[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            int current = a[i];
            int j = i;
            while (j > 0 && a[j - 1] > current)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = current;
        }
    }

    void SelectionSort(int a[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            int indexMin = i;
            for (int j = i + 1; j < length; j++)
            {
                if (a[j] < a[indexMin])
                    indexMin = j;
            }
            int temp = a[i];
            a[i] = a[indexMin];
            a[indexMin] = temp;
        }
    }

    void merge(int a[], int first, int middle, int last)
    {
        int first1 = first, last1 = middle;
        int first2 = middle + 1, last2 = last;
        int tempArr[100];
        int i = first;
        while (first1 <= last1 && first2 <= last2)
        {
            if (a[first1] < a[first2])
            {
                tempArr[i] = a[first1];
                first1++;
            }
            else
            {
                tempArr[i] = a[first2];
                first2++;
            }
            i++;
        }
        while (first1 <= last1)
        {
            tempArr[i] = a[first1];
            first1++;
            i++;
        }
        while (first2 <= last2)
        {
            tempArr[i] = a[first2];
            first2++;
            i++;
        }
        for (int i = first; i <= last; i++)
            a[i] = tempArr[i];
    }

    void MergeSort(int a[], int first, int last)
    {
        if (first < last)
        {
            int middle = (first + last) / 2;
            MergeSort(a, first, middle);
            MergeSort(a, middle + 1, last);
            merge(a, first, middle, last);
        }
    }

    void QuickSort(int a[], int left, int right)
    {
        int i = left, j = right;
        int middle = a[(left + right) / 2];

        do
        {
            while (a[i] < middle && i <= right)
                i++;
            while (middle < a[j] && left <= j)
                j--;
            if (i <= j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);

        if (left < j)
            QuickSort(a, left, j);
        if (j < right)
            QuickSort(a, i, right);
    }

    bool isLeaf(int a[], int index, int n)
    {
        if (n / 2 <= index)
            return true;
        return false;
    }

    void maxHeapify(int a[], int i, int n)
    {
        // n is heap size of array a; i is index of current root
        if (!isLeaf(a, i, n))
        {
            int left = 2 * i + 1;  // index of left child of a[i]
            int right = 2 * i + 2; // index of right child of a[i]
            int largest;
            if (left < n)
                largest = a[left] > a[i] ? left : i;
            if (right < n)
                largest = a[right] > a[largest] ? right : largest;
            if (largest != i)
            {
                int temp = a[i];
                a[i] = a[largest];
                a[largest] = temp;
                maxHeapify(a, largest, n);
            }
        }
    }

    // Create MaxHeap from an array
    void buildMaxHeap(int a[], int n)
    {
        int i = n / 2 - 1; // Roots's index are limited from 0 to n/2 -1
        while (i >= 0)
        {
            maxHeapify(a, i, n);
            i--;
        }
    }

    void HeapSort(int a[], int n)
    {
        buildMaxHeap(a, n);
        // swap a[0] and a[n-1] with n is lenght of array a[]
        if (n > 1)
        {
            int temp = a[0];
            a[0] = a[n - 1];
            a[n - 1] = temp;
            HeapSort(a, n - 1);
        }
    }

    int getHeapMax(int a[])
    {
        return a[0];
    }

    int extractHeapMax(int a[], int n)
    {
        int max = a[0];
        a[0] = a[n - 1];
        buildMaxHeap(a, n - 1);
        return max;
    }

    void increaseHeapKey(int a[], int n, int i, int value)
    {
        if (value < a[i])
            printf("New Key's value is less than original Key\n");
        else
        {
            a[i] = value;
            buildMaxHeap(a, n);
        }
    }

    void CountingSort(int a[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] < a[0])
                    count++;
            }
            int temp = a[0];
            a[0] = a[count];
            a[count] = temp;
        }
    }

    // // INSERTION SORT
    int arr1[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19, 58, 39, 90, 38, 91};
    int length = sizeof(arr1) / sizeof(int);

    // printf("\nOriginal Array: [ ");
    // printfArray(arr1, length);

    // InsertSort(arr1, length);

    // printf("\nInsertion Sort Array: [ ");
    // printfArray(arr1, length);
    // printf("*******************************************************************************\n");

    // // SELECTION SORT
    // int arr2[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19, 58, 39, 90, 38, 91};

    // printf("\nOriginal Array: [ ");
    // printfArray(arr2, length);

    // SelectionSort(arr2, length);

    // printf("\nSelection Sort Array: [ ");
    // printfArray(arr2, length);
    // printf("*******************************************************************************\n");

    // // MERGE SORT
    // int arr3[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19, 58, 39, 90, 38, 91};

    // printf("\nOriginal Array: [ ");
    // printfArray(arr3, length);

    // MergeSort(arr3, 0, length - 1);

    // printf("\nMergesion Sort Array: [ ");
    // printfArray(arr3, length);
    // printf("*******************************************************************************\n");

    // // QUICK SORT
    // int arr4[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19, 58, 39, 90, 38, 91};

    // printf("\nOriginal Array: [ ");
    // printfArray(arr4, length);

    // QuickSort(arr4, 0, length - 1);

    // printf("\nQuicktion Sort Array: [ ");
    // printfArray(arr4, length);
    // printf("*******************************************************************************\n");

    // // BUILD MAX HEAP
    // int arr5[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19};
    // int n = sizeof(arr5) / sizeof(int);

    // printf("\nOriginal Array: [ ");
    // printfArray(arr5, n);

    // buildMaxHeap(arr5, n);

    // printf("\nMax Heap Array: [ ");
    // printfArray(arr5, n);

    // HeapSort(arr5, n);
    // printf("\nHeapSort Array: [ ");
    // printfArray(arr5, n);

    // printf("\nExtracted Array: [ ");
    // printfArray(arr5, n - 1);

    // increaseHeapKey(arr5, n, 3, 10);

    // printf("\nIncreased Array: [ ");
    // printfArray(arr5, n);

    // // COUNTING SORT
    int arr6[] = {11, 17, 8, 7, 9, 3, 21, 18, 12, 57, 19, 58, 39, 90, 38, 91};

    printf("\nOriginal Array: [ ");
    printfArray(arr6, length);

    CountingSort(arr6, length);

    printf("\nCounting Sort Array: [ ");
    printfArray(arr6, length);
    // printf("*******************************************************************************\n");
}