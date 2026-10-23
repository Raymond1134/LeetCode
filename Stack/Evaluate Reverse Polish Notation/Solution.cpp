class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> tokenStack;

        for (string tok : tokens) {
            if (tok == "+") {
                int second = tokenStack.back();
                tokenStack.pop_back();
                int first = tokenStack.back();
                tokenStack.pop_back();
                tokenStack.push_back(first + second);
            }
            else if (tok == "-") {
                int second = tokenStack.back();
                tokenStack.pop_back();
                int first = tokenStack.back();
                tokenStack.pop_back();
                tokenStack.push_back(first - second);
            }
            else if (tok == "*") {
                int second = tokenStack.back();
                tokenStack.pop_back();
                int first = tokenStack.back();
                tokenStack.pop_back();
                tokenStack.push_back(first * second);
            }
            else if (tok == "/") {
                int second = tokenStack.back();
                tokenStack.pop_back();
                int first = tokenStack.back();
                tokenStack.pop_back();
                tokenStack.push_back(first / second);
            }
            else {
                tokenStack.push_back(std::stoi(tok));
            }
        }

        return tokenStack.back();
    }
};
