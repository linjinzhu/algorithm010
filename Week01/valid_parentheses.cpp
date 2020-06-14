#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

// 20.有效的括号

class Solution
{
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> symbols;
        symbols['{'] = '}';
        symbols['['] = ']';
        symbols['('] = ')';

        std::stack<char> _stack;
        for (char c : s) {
            if (symbols.find(c) == symbols.end()) {
                 if (_stack.empty()) {
                    return false;
                }
                
                // 右括号，pop
                char left = _stack.top();
                _stack.pop();
                char right = c;
                if (symbols[left] != right) {
                    return false;
                }
            } else {
              // 左括号
                _stack.push(c);
            }
        }

        return _stack.empty();
    }
};

int main(int argc, char const *argv[])
{
    // std::string kuohao = "((((()))){{{{]]]]]";
    std::string kuohao = "()";
    Solution s;
    bool result = s.isValid(kuohao);
    std::cout << "result:" << result << std::endl;
    return 0;
}
