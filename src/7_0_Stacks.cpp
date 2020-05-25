#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

int solution(std::vector<int> &A) {
    int size = 0, result = 0;
    for (auto &c : A) {
        if (c==0) {
            size += 1;
        } else {
            size -= 1;
            result = std::max(result, -size);
        }
    }
    return result;
}

int main() {
    std::vector<int> test{1,1,0};
    std::cout << solution(test);
    return 0;
}