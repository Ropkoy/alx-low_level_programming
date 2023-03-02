/**
 * reverse_array - Reverses the content of an array of integers.
 * @a: A pointer to the first element of the array.
 * @n: The number of elements in the array.
 */
void reverse_array(int *a, int n)
{
    int i, tmp;

    for (i = 0; i < n / 2; i++)
    {
        tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}
