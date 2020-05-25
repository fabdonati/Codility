#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <stack>

int solution(std::string &S) {
    std::stack<char> brackets;
    int flag = 0;
    for (auto const &c : S) {
        if (c=='(') {
            brackets.push(c);
            flag = 1;
        }
        if (!brackets.empty()) {
            if (c == ')') {
                if (brackets.top() == '(') {
                    brackets.pop();
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } 
    return (brackets.empty() && flag) || S.empty();  
}


int main() {
    std::string test;
    test = "())";
    std::cout << solution(test);
    return 0;
}