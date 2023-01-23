#include "sort.h"

/**
 * Swap - swaps two values
 * @A: the first value
 * @B: the second value
 */
void Swap(int *A, int *B)
{
int tmp;
tmp = *A;
*A = *B;
*B = tmp;
}


/**
 * partition - partitions the array
 * @array: an array of integers
 * @low: lower end array index
 * @high: higher end array index
 * @size: max index size of the array
 * Return: index for the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int l = low, h = high;

while (1)
{
while (array[l] < pivot)
l++;
while (array[h] > pivot)
h--;

if (l < h)
{
Swap(&array[l], &array[h]);
print_array(array, size);
l++;
h--;
}
else
{
if (l != h)
return (h);
return (h - 1);
}
}
}

/**
 * hoare_qsort - implements the hoare partition scheme
 * @array: an array of integers
 * @low: low end index of the array
 * @high: high end index of the array
 * @size: max index size of the array
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
int i;
if (low < high)
{
i = partition(array, low, high, size);
if (i > low)
hoare_qsort(array, low, i, size);
hoare_qsort(array, i + 1, high, size);
}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending using quick sort
 * @array: an array of integers
 * @size: maximum size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
hoare_qsort(array, 0, size - 1, size);
}
