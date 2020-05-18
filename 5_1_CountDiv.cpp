#include <iostream>
#include <algorithm>
#include <vector>

int solution(int A, int B, int K) {
    return B/K-A/K + (A%K==0 ? 1 : 0);
}

int main() {
    std::cout << solution(6,11,2);
}