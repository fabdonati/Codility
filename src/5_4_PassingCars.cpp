#include <iostream>
#include <algorithm>
#include <vector>

int solution(std::vector<int> &v) {
    int numberOfPassingCars = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == 0) {
            for (auto itInt = it; itInt != v.end(); itInt++) {
                if (*itInt == 1) {
                    numberOfPassingCars++;
                }
            }
        }
    }
    return numberOfPassingCars;
}

// faster
int solution2(std::vector<int> &v) {
    int numberOfPassingCars = 0;
    int counter = 0;
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        if (*it) {
            counter++;
        } else {
            numberOfPassingCars += counter;
        }
    }
    return numberOfPassingCars;
}

int main() {
    std::vector<int> v{0,1,1,0,1,0};
    std::cout << solution2(v);
}