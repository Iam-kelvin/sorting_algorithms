#include "sort.h"

/**
 * bubble_sort - sorts array of integer using Bubble Sort
 * @array: pointer to the array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
int max;
size_t i, j;

for (i = size; i > 1; i--)
{
for (j = 0; j < i - 1; j++)
{
if (array[j] > array[j + 1])
{
max = array[j];
array[j] = array[j + 1];
array[j + 1] = max;
print_array(array, size);
}
}
}
}
