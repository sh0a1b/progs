#include <stdio.h>
#include <stdlib.h>

void combo_set(long int arr[], long int size) {
    long int i, j, set = 1, max = arr[0], sum = 0;

    while (set <= size) {
        for (i = 0; i < size; i++) {
            if (i + set - 1 < size) {
                //printf("%d ", arr[i]);
                sum = arr[i];
                for (j = i+1; j< i + set; j++) {
                    // printf("%d ", arr[j]);
                    sum += arr[j];
                }
            } else {
                break;
            }
            if (sum > max) {
                max = sum;
            }
            // printf("\n");
        }
        set++;
    }
    printf("%ld", max);
    printf("\n");
}

int main() {
    // Test cases
    // int arr[] = {1, 2, 3, 4}; // answer: 10
    // int arr[] = {1, 2, 3, -2, 5}; // answer: 9
    // int arr[] = {-1, -2, -3, -4}; // answer: -1

    int num_test_cases;
    long int size;
    long int *arr = NULL;
    scanf("%d", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++) {
        scanf("%ld", &size);
        arr = (long int *) malloc(size * sizeof(long int));
        if (arr == NULL) {
            return 0;
        }
        for (long int j = 0; j< size; j++) {
            scanf("%ld", &arr[j]);
        }
        combo_set(arr, size);
        free(arr);
    }
    // int size = sizeof(arr)/sizeof(int);
    // combo_set(arr, size);
    return 0;
}