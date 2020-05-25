#include <algorithm>
#include <vector>
#include <iostream>

int solution(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    if (!std::count(A.end()-3, A.end(), 0)) {
            return std::max(A[A.size()-1]*A[A.size()-2]*A[A.size()-3], A[0]*A[1]*A[A.size()-1]);
    } else {
        return 0;
    }
}

int main() {
    std::vector<int> test{4, 5, 1, 0};
    std::cout << solution(test);
    return 0;
}