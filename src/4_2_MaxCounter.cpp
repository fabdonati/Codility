#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> counters(N,0);
    std::map<int,int> mp;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > N) {
            std::fill(A.begin(), A.end() - 1, A[i]);
        } else {
            counters[A[i]]++;   
        }
    }
    return counters;
}

int main() {
    std::vector<int> v{3, 4, 4, 6, 1, 4, 4};
    std::vector<int> countersSolution = solution(5, v);
    for (auto it = countersSolution.begin(); it != countersSolution.end(); it++) {
        std::cout << *it;
    }
}


