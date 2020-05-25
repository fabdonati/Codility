#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

int solution(std::vector<int> &A) {
    int counter = 0;
    for (int i = 0; i<A.size(); i++) {
        for(int j = 0; j<A.size(); j++) {
            if (i<j && (abs(j-i) <= A[i] + A[j])) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    std::vector<int> test{1,5,2,1,4,0};
    std::cout << solution(test);
    return 0;
}