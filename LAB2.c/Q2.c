/*
-------------------------------------------------------
Program    : Question 2
Subject    : Design and Analysis of Algorithms
topic      :  MERGE SORT VS MODIFIED MERGE SORT
Language   : C
Author     : Ranjan kumar Nandi
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
/*

    Normal Merge Sort:
    T(n) = 2T(n/2) + O(n)
         = O(n log n)

    Modified Three-Way Merge Sort:
    T(n) = 3T(n/3) + O(n)
         = O(n log n)

    Therefore, both algorithms have the same
    worst-case time complexity:

            O(n log n)

    This program compares the running time of
    both algorithms for different input sizes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- NORMAL MERGE SORT ---------- */

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *b = malloc((r - l + 1) * sizeof(int));

    while(i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while(i <= m)
        b[k++] = a[i++];

    while(j <= r)
        b[k++] = a[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = b[k];

    free(b);
}

void mergeSort(int a[], int l, int r)
{
    if(l >= r)
        return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}


/* ---------- THREE-WAY MERGE SORT ---------- */

void merge3(int a[], int l, int m1, int m2, int r)
{
    int i = l, j = m1 + 1, k = m2 + 1, p = 0;
    int *b = malloc((r - l + 1) * sizeof(int));

    while(i <= m1 || j <= m2 || k <= r)
    {
        if(i > m1)
        {
            if(j > m2)
                b[p++] = a[k++];
            else if(k > r || a[j] <= a[k])
                b[p++] = a[j++];
            else
                b[p++] = a[k++];
        }
        else if(j > m2)
        {
            if(k > r || a[i] <= a[k])
                b[p++] = a[i++];
            else
                b[p++] = a[k++];
        }
        else if(k > r)
        {
            if(a[i] <= a[j])
                b[p++] = a[i++];
            else
                b[p++] = a[j++];
        }
        else
        {
            if(a[i] <= a[j] && a[i] <= a[k])
                b[p++] = a[i++];
            else if(a[j] <= a[i] && a[j] <= a[k])
                b[p++] = a[j++];
            else
                b[p++] = a[k++];
        }
    }

    for(i = l, p = 0; i <= r; i++, p++)
        a[i] = b[p];

    free(b);
}

void mergeSort3(int a[], int l, int r)
{
    if(l >= r)
        return;

    int n = r - l + 1;

    int m1 = l + n / 3;
    int m2 = l + 2 * n / 3;

    if(m1 == l)
        m1++;

    if(m2 <= m1)
        m2 = m1 + 1;

    if(m2 > r)
        m2 = r;

    mergeSort3(a, l, m1 - 1);
    mergeSort3(a, m1, m2 - 1);
    mergeSort3(a, m2, r);

    merge3(a, l, m1 - 1, m2 - 1, r);
}


/* ---------- MAIN ---------- */

int main()
{
    int n, i;

    printf("n\tMerge Sort\tThree-Way Merge Sort\n");

    for(n = 1000; n <= 10000; n += 1000)
    {
        int *a = malloc(n * sizeof(int));
        int *b = malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
        {
            a[i] = rand();
            b[i] = a[i];
        }

        clock_t start = clock();

        mergeSort(a, 0, n - 1);

        double t1 = (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();

        mergeSort3(b, 0, n - 1);

        double t2 = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\n", n, t1, t2);

        free(a);
        free(b);
    }

    return 0;
}