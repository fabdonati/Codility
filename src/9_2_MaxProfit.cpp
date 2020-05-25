#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) {
    int maxEnding = 0;
    int maxProfit = 0;

    if (A.size() < 2) {
        return 0;
    }
    std::vector<int> deltas(A.size()-1, 0);
    for (size_t i = 1; i<A.size(); i++) {
        deltas[i-1] = A[i]-A[i-1];
    }
    
    for (size_t i = 0; i<deltas.size(); i++) {
        maxEnding = std::max(0, maxEnding + deltas[i]);
        maxProfit = std::max(maxProfit, maxEnding);
    }
    return maxProfit;
}

int main() {
    std::vector<int> test{23171, 21011, 21123, 21366, 21013, 21367};
    std::cout << solution(test);
    return 0;
}