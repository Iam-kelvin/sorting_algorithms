#include "sort.h"

/**
 * selection_sort - sorts in ascending order using selection sort
 * @array: an array of integers
 * @size: max size of the array
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
int tmp;
size_t i, j = 0, index_min = 0;
if (array == NULL || size < 2)
return;
for (j = 0; j < size; j++)
{
index_min = j;
for (i = j + 1; i < size; i++)
{
if (array[i] < array[index_min])
{
index_min = i;
}
}
if (array[index_min] != array[j])
{
tmp = array[index_min];
array[index_min] = array[j];
array[j] = tmp;
print_array(array, size);
}
}
}
