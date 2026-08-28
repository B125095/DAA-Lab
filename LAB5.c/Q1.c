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
    int a[100], n, i;
    int left, right;
    float median;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 != 0)
    {
        median = quickSelect(a, 0, n - 1, n / 2);
    }
    else
    {
        left = quickSelect(a, 0, n - 1, n / 2 - 1);
        right = quickSelect(a, 0, n - 1, n / 2);

        median = (left + right) / 2.0;
    }

    printf("Median = %.2f\n", median);

    return 0;
}