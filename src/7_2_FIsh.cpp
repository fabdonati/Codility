#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

int solution(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> upstreamFishes = {};
    int survivors = (int)A.size();

    for (int i=0; i<A.size(); i++) {
        if (B[i]==1) {
            upstreamFishes.push_back(i);
        } else {
            int j = (int)upstreamFishes.size() - 1;
            while(upstreamFishes.size()>0 && j>-1) {
                if (A[upstreamFishes[j]] > A[i]) {
                    survivors--;
                    break;
                } else {
                    survivors--;
                    upstreamFishes.erase(upstreamFishes.begin() + j);
                    j--;
                }
            }
        }
    }
    return survivors;
}


int main() {
    std::vector<int> size{1,3,2};
    std::vector<int> dir{1,1,0};
    std::cout << solution(size, dir);
    return 0;
}