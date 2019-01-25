#include<stdio.h>
#include<stdlib.h>

void sub_array_with_sum(long arr[], long size, long sum) {
    long interim = 0, i = 0, j = 0;
    int found = 0;

    for (i = 0; i < size && !found; i++) {
        interim = arr[i];
        j = i + 1;
        while (j < size && !found) {
            if (interim < sum) {
                interim += arr[j];
                j++;
                continue;
            } else if (interim > sum) {
                interim -= arr[i];
                i++;
                continue;
            } else if (interim == sum) {
                printf("%ld %ld\n", i+1, j);
                found = 1;
                break;
            }
            // printf("i=%ld j=%ld interim=%ld sum=%ld\n", i, j, interim, sum);
        }
        //
        // when sum includes last array element.
        // j=size, so it didn't enter the while loop and found is not set to 1
        // but interim=sum, so print it after while loop.
        if (!found && interim == sum) {
            printf("%ld %ld\n", i+1, j);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("%d\n", -1);
    }
}

int main() {
    int num_of_tests, i;
    long size, sum, *arr = NULL, j;

    scanf("%d", &num_of_tests);
    for(i = 0; i < num_of_tests; i++) {
        scanf("%ld %ld", &size, &sum);
        arr = (long *) malloc(size * sizeof(long));
        if (arr == NULL) {
            printf("failed to allocate memory\n");
            return -1;
        }
        for(j = 0 ; j < size; j++) {
            scanf("%ld", &arr[j]);
        }
        // for(j = 0 ; j < size; j++) {
        //     printf("%ld", arr[j]);
        // }
        sub_array_with_sum(arr, size, sum);
        free(arr);
    }
    return 0;
}