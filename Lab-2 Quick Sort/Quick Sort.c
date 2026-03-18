#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<high ; j++){
        if(arr[j]< pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;

}

void quick_sort(int arr[], int low, int high){
    if(low<high){
        int index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    srand(time(NULL));
    for(i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    printf("Generated array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    clock_t start, end;

    start = clock();

    quick_sort(arr, 0, n - 1);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}

