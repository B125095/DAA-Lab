/*
-------------------------------------------------------
Program    : Question 3
Subject    : Design and Analysis of Algorithms
topic      : METHOD 1: MERGE ARRAYS ONE BY ONE
Language   : C
Author     : Ranjan kumar Nandi
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
/*
We are given k sorted arrays, each containing n elements.

First, we merge the first two arrays.
The result contains 2n elements.

Then, we merge this result with the third array.
The result contains 3n elements.

We continue this process until all k arrays are merged.

The running time is:

O(2n + 3n + 4n + ... + kn)

Therefore:

O(nk^2)

So the worst-case running time of Method 1 is:

O(nk^2)
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int b[], int c[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

int main()
{
    int k, n;

    scanf("%d %d", &k, &n);

    int **a = (int **)malloc(k * sizeof(int *));

    for(int i = 0; i < k; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int *result = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        result[i] = a[0][i];
    }

    int resultSize = n;

    for(int i = 1; i < k; i++)
    {
        int newSize = resultSize + n;

        int *newResult = (int *)malloc(newSize * sizeof(int));

        merge(result, a[i], newResult, resultSize, n);

        free(result);

        result = newResult;
        resultSize = newSize;
    }

    for(int i = 0; i < resultSize; i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");

    for(int i = 0; i < k; i++)
    {
        free(a[i]);
    }

    free(a);
    free(result);

    return 0;
}