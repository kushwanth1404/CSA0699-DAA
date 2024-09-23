#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    if (item2->ratio < item1->ratio) return -1;
    return 0;
}

// Function to perform the fractional knapsack problem
float knapsack(Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fractional part of the item
            int remaining = capacity - currentWeight;
            totalValue += items[i].value * ((float)remaining / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    // Input: Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Dynamically allocate memory for items array
    Item *items = (Item *)malloc(n * sizeof(Item));

    // Input: Value, Weight, and Capacity
    printf("Enter the value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Compute the maximum value that can be carried
    float maxValue = knapsack(items, n, capacity);

    // Output the result
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    // Free the allocated memory
    free(items);

    return 0;
}
