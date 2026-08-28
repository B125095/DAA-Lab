#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    int p;

    while (low <= high)
    {
        p = partition(a, low, high);

        if (p == k)
            return a[p];

        if (k < p)
            high = p - 1;
        else
            low = p + 1;
    }

    return -1;
}

int main()
{
    int a[100], n, k, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid K\n");
        return 0;
    }

    result = quickSelect(a, 0, n - 1, k - 1);

    printf("%d-th smallest element = %d\n", k, result);

    return 0;
}