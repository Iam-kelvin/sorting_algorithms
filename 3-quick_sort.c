#include "sort.h"

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
int l = low - 1, h, tmp;
for (h = low; h < high; h++)
{
if (array[h] <= pivot)
{
l++;
if (l == h)
continue;
tmp = array[l];
array[l] = array[h];
array[h] = tmp;
print_array(array, size);
}
}
if (array[high] <= array[l + 1])
{
l++;
if (l == high)
return (l);
tmp = array[l];
array[l] = array[high];
array[high] = tmp;
print_array(array, size);
}
return (l);
}

/**
 * lomuto_qsort - implements the Lomuto partition scheme
 * @array: an array of integers
 * @low: low end index of the array
 * @high: high end index of the array
 * @size: max index size of the array
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
int i;
if (low < high)
{
i = partition(array, low, high, size);
lomuto_qsort(array, low, i - 1, size);
lomuto_qsort(array, i + 1, high, size);
}
}

/**
 * quick_sort - sorts array of integers in ascending using quick sort
 * @array: an array of integers
 * @size: maximum size of the array
 */
void quick_sort(int *array, size_t size)
{
lomuto_qsort(array, 0, size - 1, size);
}
