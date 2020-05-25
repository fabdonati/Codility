// A non-empty array A consisting of N integers is given.

// The leader of this array is the value that occurs in more than half of the elements of A.

// An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

// For example, given array A such that:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2
// we can find two equi leaders:

// 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
// 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
// The goal is to count the number of equi leaders.

// Write a function:

// class Solution { public int solution(int[] A); }

// that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

// For example, given:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2
// the function should return 2, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int solution(std::vector<int> &A) {
    int candidate = -1;
    int count = 0;
    int countA = 0;
    int countB = 0;
    int numEquileaders = 0;
    const int N = A.size();

    std::stack<int> pile;
    for (auto const &v : A) {
        if (pile.empty()) {
            pile.push(v);
        } else {
            if (pile.top() != v) {
                pile.pop();
            } else {
                pile.push(v);
            }
        }
    } 
    if (!pile.empty()) {
        candidate = pile.top();
    } else {
        return 0;
    }
    for (auto const &v : A) {
        if (v==candidate) {
            count++;
        }
    }
    if (count <= N / 2) {
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (A[i]==candidate) {
            countA++;
        }
        countB = count - countA;
        if (countA > ((double)i+1)/2 && countB > (N-((double)i+1))/2) {
            numEquileaders++;
        }
    }
    return numEquileaders;
}

int main() {
std::vector<int> test{4,3,4,4,4,2};
std::cout << solution(test);
return 0;
}