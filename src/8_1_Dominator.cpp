/*
An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

int solution(std::vector<int> &A) {
    std::stack<int> pile;
    int count = 0;
    int candidate = 0;
    if (A.size()>0) {
        // if stack is empty, push the element; if top element on stack is different, remove it
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
        candidate = pile.top();
        for (auto const &v : A) {
            if (v==candidate) {
                count++;
            }
        }
        return (count > (int)A.size() / 2) ? std::distance(A.begin(),std::find(A.begin(), A.end(), candidate)) : -1;
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> test{3,4,3,2,3,-1,3,3};
    std::cout << solution(test);
    return 0;
}