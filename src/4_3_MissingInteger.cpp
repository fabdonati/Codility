// you can use includes, for example:
 #include <algorithm>
 #include <vector>
 #include <iostream>
 #include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
    A.erase(std::remove_if(A.begin(), A.end(),  [](const int i) {return i < 0; }), A.end());
    std::sort(A.begin(), A.end());
	A.erase(std::unique(A.begin(), A.end()), A.end());
    int i = 0;
    while (A[i] == i+1) {
        i++;
    }
    return i+1;
}

int solution2(std::vector<int> &A) {
    size_t size = A.size() + 1;
    std::map<int, bool> occurs;

    for (size_t i = 0; i < size; i++) {
        if (A[i] > 0 && A[i] <= A.size()) {
            occurs[A[i] - 1] = true;
        }
    }
    for (size_t i = 0; i < size; ++i) {
        if (occurs[i] == false) {
             return i + 1;
        } 
    }
    return 0;
}

int main() {
    std::vector<int> v{-1, 4, 4, 6, 1, 4, 4};
    std::cout << solution(v);
}