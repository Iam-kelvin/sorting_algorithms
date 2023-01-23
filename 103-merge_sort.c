#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * merge - merges subarrays to higher array
 * @array: an array of integers
 * @tmp_sort: temporary sorted subarray
 * @low: low end index of array
 * @mid: mid index of array
 * @high: high end index of array
 */
void merge(int *array, int *tmp_sort, size_t low, size_t mid, size_t high)
{
size_t l, m, k, n = high - low;
l = low;
m = mid;
printf("Merging...\n");
printf("[left]: ");
print_array((const int *)array + low, mid - low);
printf("[right]: ");
print_array((const int *)array + mid, high - mid);
for (k = 0; k < n; k++)
{
if (l < mid && (m >= high || array[l] <= array[m]))
{
tmp_sort[k + low] = array[l];
l++;
}
else
{
tmp_sort[k + low] = array[m];
m++;
}
}
printf("[Done]: ");
print_array((const int *)tmp_sort + low, n);
}

/**
 * m_split - divides the array into subarrays
 * @tmp_sort: temporary sorted subarray
 * @array: an array of integers
 * @low: low end index of array
 * @high: high end index of array
 */
void m_split(int *tmp_sort, int *array, size_t low, size_t high)
{
size_t mid;
if (high - low <= 1)
return;
mid = (low + high) / 2;
m_split(array, tmp_sort, low, mid);
m_split(array, tmp_sort, mid, high);
merge(tmp_sort, array, low, mid, high);
}

/**
 * copy_to_input - copies sorted array to input array
 * @array: an array of integers
 * @tmp_sort: temporary sorted subarray
 * @size: max index size of array
 */
void copy_to_input(int *array, int *tmp_sort, size_t size)
{
size_t i;
for (i = 0; i < size; i++)
array[i] = tmp_sort[i];
}

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort
 * @array: an array of integers
 * @size: max index size of the array
 */
void merge_sort(int *array, size_t size)
{
int *tmp_sort;

if (array == NULL || size <= 1)
return;

tmp_sort = malloc(sizeof(array[0]) * size);
if (!tmp_sort)
return;

copy_to_input(tmp_sort, array, size);
m_split(tmp_sort, array, 0, size);
free(tmp_sort);
}
