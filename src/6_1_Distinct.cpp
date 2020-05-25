#include <algorithm>
#include <vector>
#include <iostream>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(std::vector<int> &A) {
    int min_idx;

    for (int i=0; i<A.size()-1; i++) {
        min_idx = i;
        for (int j=i+1; j < A.size(); j++) {
            if (A.at(j) < A.at(min_idx)) {
                min_idx = j;
                swap(&A[min_idx], &A[i]);
            }
        }
    }
}

void bubbleSort(std::vector<int> &A) {
    int min_idx;

    for (int i=0; i<A.size()-i; i++) {
        if (A[i] > A[i+1]) {
            swap(&A[i], &A[i+1]);
        }
    }
}

int solution(std::vector<int> &A) {
    //std::sort(A.begin(), A.end());
    // selectionSort(A);
    // bubbleSort(A);
    // for (auto const &c : A) {
    //     std::cout << c << std::endl;
    // }
    return std::distance(A.begin(), std::unique(A.begin(), A.end()));
}

int main() {
    std::vector<int> v{2,1,1,2,2,2,3,4,5,5};
    std::cout << "solution is = " << solution(v);
    return 0;
}