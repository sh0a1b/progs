#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *arr, int size) {
    int i, j, k = 0;

    for(i = 0; i< size; i++) {
        if(arr[i] == 0) {
            k++;
        }
    }
    for (i = 0, j = size - 1; i < j && k <= j;) {
        while(arr[i] == 0) {
            i++;
        }
        while (arr[k] == 1) {
            k++;
        }
        while (arr[j] == 2) {
            j--;
        }

        if (i > j || k > j) break;
        if (arr[i] == 1 && arr[k] == 0) {
            swap(&arr[i], &arr[k]);
            i++; k++;
            continue;
        }
        if (arr[i] == 2 && arr[j] == 0) {
            swap(&arr[i], &arr[j]);
            i++; j--;
            continue;
        }
        if (arr[k] == 2 && arr[j] == 1) {
            swap(&arr[k], &arr[j]);
            k++; j--;
            continue;
        }
        if (arr[i] == 1 && arr[k] == 2 && arr[j] == 0) {
            swap(&arr[i], &arr[j]);
            swap(&arr[j], &arr[k]);
            i++; k++; j--;
            continue;
        }
        if (arr[i] == 2 && arr[k] == 0 && arr[j] == 1) {
            swap(&arr[i], &arr[k]);
            swap(&arr[k], &arr[j]);
            i++; k++; j--;
            continue;
        }
    }
}
/* void sort_array(int *arr, int size) {
    int i, j, k = -1;

    for (i = 0, j = size-1; i < j;) {
        while (arr[i] == 0) {
            i++;
        }
        while (arr[j] == 2) {
            j--;
        }

        if (arr[i] == 1 && arr[j] == 0) {
            if (k > 0 && k < i) {
                swap(&arr[k], &arr[j]);
                k++; i++;
                // dont decrement j, coz a[j] will be 1, which might need processing.
            } else {
                swap(&arr[i], &arr[j]);
                k = j;
                // dont decrement j, coz a[j] will be 1, which might need processing.
                i++;
            }
            //continue;
        }

        if (arr[i] == 2 && arr[j] == 1) {
            if (k == -1 || k > i) {
                // 1 will be moved to arr[i], set k to i
                k = i;
            }
            swap(&arr[i], &arr[j]);
            // dont decrement i, coz a[i] will be 1, which might need processing.
            j--;
            //continue;
        }

        if (arr[i] == 2 && arr[j] == 0) {
            swap(&arr[i], &arr[j]);
            i++; j--;
            //continue;
        }

        if (arr[i] == 1 && arr[j] == 1) {
            if (k == -1 || k > i) {
                k = i;
            }
            i++;
            //continue;
        }
    }
    while (k != -1 && k<j) {
        if(arr[k] == 1 && arr[j] == 0) {
            swap(&arr[k], &arr[j]);
            k++; j--;
        } else if (arr[k] == 1 && arr[j] == 1) {
            j--;
        }
    }
}*/


int main () {
    //int *arr = NULL;
    //int size = 8, i;

    // arr = (int *) malloc(size * sizeof(int));
    // if (arr == NULL) {
    //     printf("mem alloc failed\n");
    //     return -1;
    // }
    // arr[0] = 0;
    // arr[1] = 1;
    // arr[2] = 2;
    // arr[3] = 0;
    // arr[4] = 1;
    // arr[5] = 0;
    // arr[6] = 1;
    // arr[7] = 2;

    // int arr[] = {0, 1, 2, 0, 1}, size = 5;
    // int arr[] = {0, 2, 1, 2, 1}, size = 5;
    // int arr[] = {0, 2, 1, 2, 0}, size = 5;
    // int arr[] = {0, 1, 2, 0, 1, 0, 1, 2}, size = 8;
    // int arr[] = {0, 1, 0}, size = 3;

    int i, j, k;

    int num_of_tests, size, *arr = NULL;
    
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
        sort_array(arr, size);
        for (k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        free(arr);
    }
    // printf("before sorting: ");
    // for (i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // sort_array(arr, size);

    // printf("\nafter  sorting: ");
    // for (i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    //free(arr);
    return 0;
}