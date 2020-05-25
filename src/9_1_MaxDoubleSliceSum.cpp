#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) {
    std::vector<int> kadane1(A.size(),0);
    std::vector<int> kadane2(A.size(),0);

    for (int i = 1; i<A.size(); i++) {
        kadane1[i] = std::max(kadane1[i-1]+A[i],0);
    }
    for (int i = A.size()-2; i>0; i--) {
        kadane2[i] = std::max(kadane2[i+1]+A[i],0);
    }
    int result = -1e6;
    for (int i = 1; i < A.size()-1; i++) {
        result = std::max(result, kadane1[i-1]+kadane2[i+1]);
    } 
    return result;
}

int main() {
    std::vector<int> test{0, 10, -5, -2, 0};
    std::cout << solution(test);
    return 0;
}