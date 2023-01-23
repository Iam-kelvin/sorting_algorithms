#include "sort.h"

/**
 * Swap - swaps two values of array
 * @array: an array of integers
 * @size: max index size of the array
 * @A: index for the first value
 * @B: index for the second value
 */
void Swap(int *array, int A, int B, const int size)
{
int tmp;
if (A != B)
{
tmp = array[A];
array[A] = array[B];
array[B] = tmp;
print_array(array, size);
}
}

/**
 * Compare - recursively compares subarrays
 * @array: an array of integers
 * @size: max index size of the array
 * @i: pivit index for subarray
 * @i_size: subarray index size
 */
void Compare(int *array, size_t size, int i, int i_size)
{
int larger = i;
int l = (2 * i) + 1;
int r = (2 * i) + 2;
if (l < (int) size && array[l] > array[larger])
larger = l;
if (r < (int) size && array[r] > array[larger])
larger = r;
if (larger != i)
{
Swap(array, i, larger, i_size);
Compare(array, size, larger, i_size);
}
}


/**
 * heap_sort - sorts an array of integers in ascending using the Heap sort
 * @array: an array of integers
 * @size: max index size of the array
 */
void heap_sort(int *array, size_t size)
{
int i, i_size = (int) size;
if (size < 2 || !array)
return;

for (i = size / 2 - 1; i >= 0; i--)
Compare(array, size, i, i_size);
for (i = size  - 1; i >= 0; i--)
{
Swap(array, 0, i, i_size);
Compare(array, i, 0, i_size);
}
}
