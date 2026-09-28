#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int change;
} Event;

int compare(const void *a, const void *b)
{
    Event *x = (Event *)a;
    Event *y = (Event *)b;

    if (x->year != y->year)
        return x->year - y->year;

    // Death (-1) before birth (+1)
    return x->change - y->change;
}

int main()
{
    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    Event events[2 * n];

    for (int i = 0; i < n; i++)
    {
        int birth, death;

        printf("Enter birth and death year of scientist %d: ", i + 1);
        scanf("%d %d", &birth, &death);

        events[2 * i].year = birth;
        events[2 * i].change = +1;

        events[2 * i + 1].year = death;
        events[2 * i + 1].change = -1;
    }

    // Sort events by year
    qsort(events, 2 * n, sizeof(Event), compare);

    int alive = 0;
    int maxAlive = 0;
    int bestYear = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        alive += events[i].change;

        if (alive > maxAlive)
        {
            maxAlive = alive;
            bestYear = events[i].year;
        }
    }

    printf("\nTime with maximum scientists alive: %d\n", bestYear);
    printf("Maximum number of scientists alive: %d\n", maxAlive);

    return 0;
}