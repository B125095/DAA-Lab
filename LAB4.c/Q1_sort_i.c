/*## Sort Items by Colour in O(n)

### Problem Statement

We are given `n` pairs of items. Each pair contains:

- A number
- A colour: `red`, `blue`, or `yellow`

The items are already sorted in ascending order of their numbers.

We need to rearrange the items so that all `red` items come first, 
followed by all `blue` items, and then all `yellow` items.

The numbers within each colour must remain sorted.

### Example

**Input:**

    1 red
    2 blue
    3 yellow
    4 red
    5 blue
    6 red
    7 yellow

**Output:**

    1 red
    4 red
    6 red
    2 blue
    5 blue
    3 yellow
    7 yellow

The numbers within each colour are still sorted.

### Key Observation

The input is already sorted by number. Therefore, we do not need to sort the numbers again.

We can simply scan the input from left to right and separate the items into three groups:

    RED    → red[]
    BLUE   → blue[]
    YELLOW → yellow[]

Since we process the input from the smallest number to the largest number, 
the numbers inside each colour group automatically remain sorted.

### Algorithm

1. Create three arrays:
   - `red[]`
   - `blue[]`
   - `yellow[]`

2. Create three counters:
   - `r = 0`
   - `b = 0`
   - `y = 0`

3. Scan all `n` input items one by one.

4. For each item:
   - If the colour is `red`, store it in `red[r]` and increment `r`.
   - If the colour is `blue`, store it in `blue[b]` and increment `b`.
   - If the colour is `yellow`, store it in `yellow[y]` and increment `y`.

5. Finally, combine the three arrays in this order:

       red[] → blue[] → yellow[]

6. The resulting array is sorted by colour while maintaining the sorted order of numbers within each colour.

### Why Does It Work?

Suppose the input contains red items with numbers:

    2, 5, 8, 12

Because the input is already sorted, we encounter these numbers in the same order. 
Therefore, after placing them into `red[]`, we get:

    red[] = {2, 5, 8, 12}

The same is true for blue and yellow items.

Therefore, separating the items by colour does not disturb the order of their numbers.

Finally, concatenating:

    RED → BLUE → YELLOW

produces the required result.

### Time Complexity

The input is scanned once:

    O(n)

The elements are then copied into the final output:

    O(n)

Therefore:

    O(n) + O(n) = O(n)

**Time Complexity: O(n)**

### Space Complexity

Three colour arrays and an output array are used to store the items.

**Space Complexity: O(n)**

### Complexity Summary

| Operation | Complexity |
|-----------|------------|
| Scan input | O(n) |
| Group by colour | O(n) |
| Create final output | O(n) |
| **Total Time** | **O(n)** |
| **Extra Space** | **O(n)** |

### Main Idea

> Since the input is already sorted by number, scan it once,
 separate the items into three colour groups,
  and concatenate the groups as **Red → Blue → Yellow**.*/
#include <stdio.h>
#include <string.h>

struct Item {
    int number;
    char color[10];
};

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item red[n], blue[n], yellow[n], output[n];

    int r = 0, b = 0, y = 0;

    printf("Enter number and color(red,blue,yellow):\n");

    for (int i = 0; i < n; i++) {
        int number;
        char color[10];

        scanf("%d %s", &number, color);

        if (strcmp(color, "red") == 0) {
            red[r].number = number;
            strcpy(red[r].color, color);
            r++;
        }
        else if (strcmp(color, "blue") == 0) {
            blue[b].number = number;
            strcpy(blue[b].color, color);
            b++;
        }
        else if (strcmp(color, "yellow") == 0) {
            yellow[y].number = number;
            strcpy(yellow[y].color, color);
            y++;
        }
    }

    int k = 0;

    // Copy red items
    for (int i = 0; i < r; i++)
        output[k++] = red[i];

    // Copy blue items
    for (int i = 0; i < b; i++)
        output[k++] = blue[i];

    // Copy yellow items
    for (int i = 0; i < y; i++)
        output[k++] = yellow[i];

    printf("\nSorted items by color:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d,|%s|)\n", output[i].number, output[i].color);
    }

    return 0;
}