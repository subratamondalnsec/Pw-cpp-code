#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to define the priority of operators
    int priority(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }
    
    // Function to perform basic arithmetic operations
    int applyOp(int val1, int val2, char op) {
        switch (op) {
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            case '/': return val1 / val2;
        }
        return 0;
    }
    bool isdigit(char ch){
        if(ch>=48 && ch<=57) return true;
        else return false;
    }
    
    // Main function to evaluate the mathematical expression
    int calculate(string s) {
        // Remove spaces from the string
        string t = "";
        for (char c : s) {
            if (c != ' ') t += c;
        }
        s = t;
        
        stack<int> values;  // Stack for values (operands)
        stack<char> ops;    // Stack for operators
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                // Read a multi-digit number
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                values.push(num);
                i--; // Adjust because the loop will increment it
            } 
            else if (s[i] == '(') {
                ops.push(s[i]);
            } 
            else if (s[i] == ')') {
                // Evaluate the expression till matching '('
                while (!ops.empty() && ops.top() != '(') {
                    int val2 = values.top(); values.pop();
                    int val1 = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.pop(); // Pop '('
            } 
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                // Handle unary minus
                if (s[i] == '-' && (i == 0 || s[i - 1] == '(')) {
                    values.push(0); // Push 0 to handle unary minus as subtraction
                }
                // Process current operator
                while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                    int val2 = values.top(); values.pop();
                    int val1 = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(s[i]);
            }
        }
        
        // Evaluate remaining operations
        while (!ops.empty()) {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(val1, val2, op));
        }
        
        return values.top();
    }
};
int main() {
    Solution sol;
    string expression = "(1+(40+5+2)-3)+(6+8)";
    int result = sol.calculate(expression);
    cout << "The result of the expression is: " << result << endl;
    return 0;
}