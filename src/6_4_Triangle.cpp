#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

int solution(std::vector<int> &A) {
    if (A.size() >= 3) {
        std::sort(A.begin(), A.end());
        for (int i=0; i<A.size()-2; i++) {
            if (A[i]+A[i+1] > A[i+2]) {
                return 1;
            }
        }
    } 
    return 0;
}

int main() {
    std::vector<int> test{1,5,2,1,4,0};
    std::cout << solution(test);
    return 0;
}