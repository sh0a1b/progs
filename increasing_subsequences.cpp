#include<iostream>
#include<vector>

using namespace std;

void print_vec(vector<int> vec) {
    for (int i = 0; i< vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void print_subsequences(int arr[], int size) {
    int i, j, k, l, deviate = 0;
    
    vector<int> vec;

    j = 1;
    for (i = 0; i < size; i++) {
        vec.push_back(arr[i]);
        //j = i+1;
        while (j<size) {
            for (k = j; k < size; k++) {
                if (vec.back() <= arr[k]) {
                    vec.push_back(arr[k]);
                } else {
                    if (deviate == 0) {
                        l = k;
                        j = k;
                        deviate = 1;
                    }
                }
            }
            print_vec(vec);
            while (arr[l] < vec.back()) {
                vec.pop_back();
            }
            if (!deviate) {
                j++;
            }
            deviate = 0;
            
            //j++;
        }
    }
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int size = sizeof(arr)/sizeof(int);

    print_subsequences(arr, size);

    return 0;
}