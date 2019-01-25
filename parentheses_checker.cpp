#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
void parentheses_checker(string arr, int size) {
    int i, temp, isBalanced = 1;
    vector<char> vec;

    for (i=0; i< size; i++) {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
            vec.push_back(arr[i]);
        } else if (arr[i] == ')') {
            temp = vec.back();
            vec.pop_back();
            if (temp != '(') {
                isBalanced = 0;
                break;
            }
        } else if (arr[i] == ']') {
            temp = vec.back();
            vec.pop_back();
            if (temp != '[') {
                isBalanced = 0;
                break;
            }
        } else if (arr[i] == '}') {
            temp = vec.back();
            vec.pop_back();
            if (temp != '{') {
                isBalanced = 0;
                break;
            }
        }
    }
    if (vec.size() == 0 && isBalanced == 1) {
        printf("balanced\n");
    } else {
        printf("not balanced\n");
    }
}

int main() {
    //const char *arr = "{([])}"; //balanced
    //const char *arr = "()"; //balanced
    //const char *arr = "([]"; //not balanced
    //string arr = "([]";
    //arr.push_back(')');
    //cout << arr.length() << endl;
    //cout << arr << std::endl;
    
    int size, num_of_tests, temp;
    char arr[101];

    scanf("%d", &num_of_tests);
    for(int i = 0; i < num_of_tests; i++) {
        //temp = fscanf(stdin, arr, sizeof(arr));
        temp = scanf("%100s", arr);
        size = sizeof(arr)/sizeof(char);
        printf("%s\t%d\t %d\n", arr, size, temp);
        parentheses_checker(arr, size);
    }

    //parenthesis_checker(arr, size);
    return 0;
}