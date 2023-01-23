#include "sort.h"


/**
 * help_sort - auxiliary function of radix sort
 * @array: an array of integers
 * @size: max index of the array
 * @lsd: Least significant digit
 * @buff: allocated buffer memory
 */
void help_sort(int *array, int **buff, int size, int lsd)
{
int i, j, asize = 10, num;
int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
for (i = 0; i < size; i++)
{
num = array[i];
for (j = 0; j < lsd; j++)
if (j > 0)
num = num / 10;
num = num % 10;
buff[num][arr[num]] = array[i];
arr[num] += 1;
}
for (i = 0, j = 0; i < asize; i++)
{
while (arr[i] > 0)
{
array[j] = buff[i][arr2[i]];
arr2[i] += 1, arr[i] -= 1;
j++;
}
}
print_array(array, size);
}


/**
 * r_sort - radix sort
 *
 * @array: an array of integers
 * @size: max index of the array
 * @lsd: Least significant digit
 */
void r_sort(int *array, int size, int lsd)
{
int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int i, j, num, asize = 10, **buff;
for (i = 0; i < size; i++)
{
num = array[i];
for (j = 0; j < lsd; j++)
if (j > 0)
num = num / 10;
num = num % 10;
arr[num] += 1;
}

if (arr[0] == size)
return;
buff = malloc(sizeof(int *) * 10);
if (!buff)
return;
for (i = 0; i < asize; i++)
if (arr[i] != 0)
buff[i] = malloc(sizeof(int) * arr[i]);
help_sort(array, buff, size, lsd);
r_sort(array, size, lsd + 1);
for (i = 0; i < asize; i++)
if (arr[i] > 0)
free(buff[i]);
free(buff);
}


/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: an array of integers
 * @size: max index size of array
 */

void radix_sort(int *array, size_t size)
{
if (size < 2)
return;
r_sort(array, size, 1);
}
