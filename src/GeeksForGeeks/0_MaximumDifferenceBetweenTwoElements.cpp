/*
Given an array arr[] of integers, find out the maximum difference between any two elements 
such that larger element appears after the smaller number.
*/

#include <iostream>

/*
    Time complextiy O(n2)
    Space complexity O(1)
*/
int solution(int arr[], int arr_size) {
    int maxDiff = -1;
    for (int i = 0; i<arr_size; i++) {
        for (int j = i+1; j<arr_size; j++) {
            if (arr[j]-arr[i] > maxDiff) {
                maxDiff = arr[j] - arr[i];
            }
        }    
    }
    return maxDiff;
}

/*
    Time complextiy O(n)
    Space complexity O(1)
*/
int solution2(int arr[], int arr_size) {
    int maxDiff = arr[0] - arr[1];
    int minElement = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return maxDiff;
}

/*
    Time complextiy O(n)
    Space complexity O(n)
*/
int solution3(int arr[], int arr_size) {
    int *diff = new int[arr_size-1];

    for (int i = 0; i < arr_size-1; i++) {
        diff[i] = arr[i+1] - arr[i];
    }

    int maxDiff = diff[0];

    for (int i = 1; i < arr_size-1; i++) {
        if (diff[i-1] > 0) {
            diff[i] += diff[i-1];
        } 
        if (maxDiff < diff[i]) {
            maxDiff = diff[i];
        }
    }
    return maxDiff;
}

int main() 
{ 
    int arr[] = {1, 2, 90, 10, 110}; 
    int n = sizeof(arr) / sizeof(arr[0]);     
    std::cout << "Maximum difference is " << solution(arr, n); 
    return 0; 
} 