class Solution {
public:
    bool isValid(string s) {
        vector<char> parenStack;
        for (char c : s) {
            switch (c) {
                case '(':
                    parenStack.push_back(')');
                    break;
                case '[':
                    parenStack.push_back(']');
                    break;
                case '{':
                    parenStack.push_back('}');
                    break;
                default:
                    if (!parenStack.empty()) {
                        if (parenStack.back() == c) parenStack.pop_back();
                        else return false;
                    }
                    else return false;
                    break;
            }
        }
        return (parenStack.empty()) ? true : false;
    }
};
