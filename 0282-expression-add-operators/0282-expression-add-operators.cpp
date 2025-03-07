class Solution {
public:
    vector<string> result;

    void backtrack(string &num, int index, long long currentValue, long long prevOperand, string expr, int target) {
        // Base case: If we've used all digits
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(expr);
            }
            return;
        }

        // Iterate over possible numbers (1-digit, 2-digit, etc.)
        for (int i = index; i < num.size(); i++) {
            string strNum = num.substr(index, i - index + 1);
            long long value = stoll(strNum); // Convert string to number

            // Avoid leading zeros (skip "05", "0007", etc.)
            if (strNum.size() > 1 && strNum[0] == '0') break;

            // First number (no operator needed before it)
            if (index == 0) {
                backtrack(num, i + 1, value, value, strNum, target);
            } else {
                // Addition
                backtrack(num, i + 1, currentValue + value, value, expr + "+" + strNum, target);

                // Subtraction
                backtrack(num, i + 1, currentValue - value, -value, expr + "-" + strNum, target);

                // Multiplication (undo last operand, apply multiplication)
                backtrack(num, i + 1, currentValue - prevOperand + prevOperand * value, prevOperand * value, expr + "*" + strNum, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        result.clear();
        backtrack(num, 0, 0, 0, "", target);
        return result;
    }
};

