#include <iostream>
#include <algorithm>
#include <vector>

int solution(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    return A.size() == A.back();
}

int main() {
    std::vector<int> test{9, 5, 7, 3, 2, 7, 3, 1, 10, 8};
    std::cout << "Vector " << (solution(test) ? "is " : "is not ") << "a permutation.";
    return 0;
}