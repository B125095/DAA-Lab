#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int largest;
    int left, right;
    int temp;

    largest = i;

    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements */
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    FILE *fp;
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    /* Store random numbers in file */
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("\nRandom elements:\n");

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;

        printf("%d ", a[i]);
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);

    /* Read numbers from file */
    fp = fopen("numbers.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    /* Heap Sort */
    heapSort(a, n);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}