#include<stdio.h>
#include<stdlib.h>

void equilibrium_point(int *arr, int size) {
    int cur, left_sum = 0, right_sum = 0, sum = 0, i, found = 0;

    /*
     * special case, size equals 1: print the element and return.
     */
    if (size == 1) {
        // return the size when there is only one element present, size equals postion+1
        printf("%d", size);
        return;
    }
    for (i = 0; i< size; i++) {
        sum += arr[i];
    }
    // initialize
    cur = 0;
    left_sum = 0;
    right_sum = sum;

//printf("sum = %d\n", sum);
    while(cur < size) {
        //printf("cur=%d left_sum=%d right_sum=%d arr[cur]=%d\n", cur, left_sum, right_sum, arr[cur]);
        if(left_sum == right_sum) {
            found = 1;
            break;
        } else {
            left_sum += arr[cur];
            cur++;
            right_sum = sum - left_sum - arr[cur];
        }
    }
    if (found) {
        /*
         * arrays are zero index based.
         */
        printf("%d", cur+1);
    } else {
        printf("%d", -1);
    }
}

int main() {
    int num_of_tests, size, *arr = NULL, i, j;

    scanf("%d", &num_of_tests);
    for(i = 0; i < num_of_tests; i++) {
        scanf("%d", &size);
        arr = (int *) malloc(size * sizeof(int));
        if (arr == NULL) {
            return -1;
        }
        for(j = 0; j< size; j++) {
            scanf("%d", &arr[j]);
        }
        equilibrium_point(arr, size);
        printf("\n");
        free(arr);
    }
    return 0;
}