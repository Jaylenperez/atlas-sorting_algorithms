#include "sort.h"

void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);
void swap(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers
 * using Quick Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    quicksort(array, 0, size - 1);
}

/**
 * quicksort - Recursively sorts a partition of an array using Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be stored
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

/**
 * partition - Partitions the array into two parts and returns the pivot index
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high - low + 1);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, high - low + 1);

    return (i + 1);
}

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
