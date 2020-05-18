#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    std::vector<int> A(S.size()+1);    
    std::vector<int> C(S.size()+1);
    std::vector<int> G(S.size()+1);
    std::vector<int> T(S.size()+1);

    for (size_t i=1; i<=S.size(); i++) {
        A[i] = A[i-1] + (S[i-1] == 'A' ? 1 : 0);
        C[i] = C[i-1] + (S[i-1] == 'C' ? 1 : 0);
        G[i] = G[i-1] + (S[i-1] == 'G' ? 1 : 0);
        T[i] = T[i-1] + (S[i-1] == 'T' ? 1 : 0);
    }
    std::vector<int> result;
    for (size_t j = 0; j < P.size(); j++) {
        if      (A[Q[j]+1]-A[P[j]]!=0) result.push_back(1);
        else if (C[Q[j]+1]-C[P[j]]!=0) result.push_back(2);
        else if (G[Q[j]+1]-G[P[j]]!=0) result.push_back(3);
        else if (T[Q[j]+1]-T[P[j]]!=0) result.push_back(4);
    }
    return result;
}

int main() {
    std::string genomic{"CAGGTA"};
    std::vector<int> P{1,3,0};
    std::vector<int> Q{4,3,5};
    std::vector<int> result;
    result = solution(genomic, P, Q);
    
    for (auto const& c: result) {
        std::cout << c << std::endl;
    }
    return 0;
}