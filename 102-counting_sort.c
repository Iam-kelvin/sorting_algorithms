#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort
 * @array: an array of integers
 * @size: max index size of the array
 */
void counting_sort(int *array, size_t size)
{
int *copy_array, *new_array, max, j;
size_t i;
if (!array || size < 2)
return;
max = array[0];
copy_array = malloc(sizeof(int) * size);
if (!copy_array)
{
free(copy_array);
return;
}
for (i = 0; i < size; i++)
{
copy_array[i] = array[i];
if (array[i] > max)
max = array[i];
}
new_array = malloc((max + 1) * sizeof(int));
if (!new_array)
{
free(copy_array);
free(new_array);
return;
}

for (j = 0; j <= max; j++)
new_array[j] = 0;
for (i = 0; i < size; i++)
new_array[array[i]] += 1;
for (j = 1; j <= max; j++)
new_array[j] += new_array[j - 1];
print_array(new_array, max + 1);

for (i = 0; i < size; i++)
{
copy_array[new_array[array[i]] - 1] = array[i];
new_array[array[i]] -= 1;
}
for (i = 0; i < size; i++)
array[i] = copy_array[i];

free(copy_array);
free(new_array);
}
