#include "sort.h"

/**
 * shell_sort - sorts array of integers using shell sort
 * @array: an array of integers
 * @size: max index size of the array
 */
void shell_sort(int *array, size_t size)
{
int n = 1, i, j, tmp;
if (!array || !size || size < 2)
return;
while (n < (int)size / 3)
n = n * 3 + 1; /* Knuth sequence */
while (n > 0)
{
for (i = n; i < (int)size; i++)
{
tmp = array[i];
j = i;
while (j > (n - 1) && array[j - n] >= tmp)
{
array[j] = array[j - n];
j -= n;
}
array[j] = tmp;
}
n = n / 3;
print_array(array, size);
}
}
