#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> stack;
        int ans = std::stoi(tokens[0]);
        stack.push_back(ans);

        for (int i = 1; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                int op2 = stack.back();
                stack.pop_back();
                int op1 = stack.back();
                stack.pop_back();

                if (tokens[i] == "+") {
                    ans = op1 + op2;
                } else if (tokens[i] == "-") {
                    ans = op1 - op2;
                } else if (tokens[i] == "/") {
                    ans = op1 / op2;
                } else if (tokens[i] == "*") {
                    ans = op1 * op2;
                }

                stack.push_back(ans);
            } else {
                stack.push_back(std::stoi(tokens[i]));
            }
        }

        return ans;
    }
};
