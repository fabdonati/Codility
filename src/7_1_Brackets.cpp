#include <iostream>
#include <string>
#include <stack> 


int solution(std::string &S) {
    std::stack<char> s;
    int flag = 0;

    for (auto const &c : S) {
        if (c=='(' || c=='[' || c=='{') {
            s.push(c);
            flag = 1;
        }
        if (!s.empty()) {
            if (c == '}') {
                if (s.top() == '{') {
                    s.pop();
                } else {
                    break;
                }
            }
            if (c == ']') {
                if (s.top() == '[') {
                    s.pop();
                } else {
                    break;
                }
            }
            if (c == ')') {
                if (s.top() == '(') {
                    s.pop();
                } else {
                    break;
                }
            }
        } else {
            break;
        }
    }
    return (s.empty() && flag);
}

int main() {
    std::string test;
    test = "";
    std::cout << (solution(test) ? "Brackets balanced" : "Brackets unbalanced");
}