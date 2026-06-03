#include <stdio.h>

void maxHeapify(int A[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && A[left] > A[largest])
        largest = left;

    if (right < size && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        maxHeapify(A, size, largest);
    }
}

void heapSort(int A[], int n)
{
    int i;

    // Build Max Heap
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);

    // Heap Sort
    for (i = n - 1; i > 0; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        maxHeapify(A, i, 0);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    heapSort(A, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
