#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <stack>

int solution(std::vector<int> &H) {
    std::stack<int> blocks;
    int blocksCounter = 0;

    for (int i=0; i<H.size(); i++) {
        while (blocks.size() > 0 && blocks.top() > H[i]) {
            blocks.pop();
        } 
        if (blocks.size() == 0 || blocks.top() < H[i]) {
            blocksCounter++;
            blocks.push(H[i]);
        }
    }
    return blocksCounter;
}


int main() {
    std::vector<int> height = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    std::cout << solution(height);
    return 0;
}