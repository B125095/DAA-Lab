/*
-------------------------------------------------------
Program    : Question 3
Subject    : Design and Analysis of Algorithms
topic      : METHOD 2: MERGE ARRAYS IN PAIRS
Language   : C
Author     : Ranjan kumar Nandi
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
/*
Instead of merging the arrays one by one,
we merge them in pairs.

For example, if k = 8:
First round:
A1 + A2
A3 + A4
A5 + A6
A7 + A8
Now there are 4 arrays.

Second round:
Merge the 4 arrays in pairs.

Now there are 2 arrays.

Third round:
Merge the remaining 2 arrays.

Now there is only 1 final sorted array.

The number of rounds is:

log2(k)

In every round, all kn elements are processed.

Therefore, the running time is:

O(kn log k)

So the worst-case running time of Method 2 is:

O(kn log k)

Method 2 is faster than Method 1.

Method 1: O(nk^2)
Method 2: O(nk log k)
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

    int *size = (int *)malloc(k * sizeof(int));

    for(int i = 0; i < k; i++)
    {
        size[i] = n;
    }

    while(k > 1)
    {
        int newK = (k + 1) / 2;

        int **next = (int **)malloc(newK * sizeof(int *));
        int *nextSize = (int *)malloc(newK * sizeof(int));

        int j = 0;

        for(int i = 0; i < k; i += 2)
        {
            if(i + 1 < k)
            {
                int newSize = size[i] + size[i + 1];

                next[j] = (int *)malloc(newSize * sizeof(int));

                merge(a[i], a[i + 1],
                      next[j], size[i], size[i + 1]);

                nextSize[j] = newSize;
                j++;
            }
            else
            {
                next[j] = a[i];
                nextSize[j] = size[i];
                j++;
            }
        }

        for(int i = 0; i < k; i++)
        {
            if(i % 2 == 0 && i + 1 >= k)
                continue;

            free(a[i]);
        }

        free(a);
        free(size);

        a = next;
        size = nextSize;
        k = newK;
    }

    for(int i = 0; i < size[0]; i++)
    {
        printf("%d ", a[0][i]);
    }

    printf("\n");

    free(a[0]);
    free(a);
    free(size);

    return 0;
}