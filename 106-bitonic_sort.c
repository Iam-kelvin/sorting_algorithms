#include "sort.h"

/**
 * printArray - prints array
 * @array: an array of integers
 * @start: start range
 * @stop: stop index
 */
void printArray(int *array, int start, int stop)
{
int i;
for (i = start; i <= stop; i++)
{
if (i > start)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}

/**
 * Swap - swap two elements of array
 * @array: an array of integres
 * @A: indexof first element
 * @B: indexof first element
 * @dir: direction to go 1: up or 0: down
 */
void Swap(int *array, int A, int B, int dir)
{
int tmp;

if (dir == (array[A] > array[B]))
{
tmp = array[A];
array[A] = array[B];
array[B] = tmp;
}
}


/**
 * b_merge - swaps elements and merges arrays
 * @array: an array of integers
 * @low: The low end array index
 * @size: The max index size of array
 * @dir: direction to go 1: up or 0: down
 * @s_size: max size of subarray index
 */
void b_merge(int *array, int low, int size, int dir, int s_size)
{
int k = size, i = low;
if (size > 1)
{
k = size / 2;
for (i = low; i < low + k; i++)
Swap(array, i, i + k, dir);
b_merge(array, low, k, dir, s_size);
b_merge(array, low + k, k, dir, s_size);
}
}


/**
 * b_sort - divides into subarray
 * @array: an array of integrs
 * @low: The low end array index
 * @size: Size of the range to sort
 * @dir: direction to go 1: up or 0: down
 * @s_size: max size of subarray index
 */
void b_sort(int *array, int low, int size, int dir, int s_size)
{
int k = size;

if (size > 1)
{
if (dir == 1)
printf("Merging [%d/%d] (UP):\n", size, s_size);
if (dir == 0)
printf("Merging [%d/%d] (DOWN):\n", size, s_size);
printArray(array, low, low + k - 1);

k = size / 2;
b_sort(array, low, k, 1, s_size);
b_sort(array, low + k, k, 0, s_size);

b_merge(array, low, size, dir, s_size);
if (dir == 1)
{
printf("Result [%d/%d] (UP):\n", size, s_size);
printArray(array, low, low + 2 * k - 1);
}
if (dir == 0)
{
printf("Result [%d/%d] (DOWN):\n", size, s_size);
printArray(array, low, low + 2 * k - 1);
}
}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: an array of integers
 * @size: max index size of the array
 */
void bitonic_sort(int *array, size_t size)
{
int up = 1;
int s_size = (int)size;
if (size < 2 || !array)
return;
b_sort(array, 0, (int)size, up, s_size);
}
