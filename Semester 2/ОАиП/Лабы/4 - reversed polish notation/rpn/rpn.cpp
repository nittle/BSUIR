#include <iostream>
#include "Stack.cpp"
#include "String.cpp"

class RPN {
private:
    RPN() {};

    static int _prec(char op) {
        if (op == '/' || op == '*') return 2;
        else if (op == '+' || op == '-') return 1;
        else return -1;
    }
    static bool _isOperator(char symbol) {
        return symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-';
    }

    static double _applyOp(double a, double b, char op) {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
        }
    }

    static int _getIndex(char arg) {
        return arg - 'a';
    }
public:
    static String getPostfix(String str) {
        Stack<char> stack;
        String res;
        // Loop through the string
        for (int i = 0; i < str.getLength(); i++)
        {
            // Get i-th character
            char ch = str[i];
            //If ch is operator
            
            // If the end of the string has been reached
            if (ch == '\0') {
                while (!stack.isEmpty()) {
                    res += stack.pop();
                }
            }
            else if (ch == '(') {
                stack.push(ch);
            }
            else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    res += stack.pop();
                }
                stack.pop();
            }
            // If ch is an operand
            else if (_isOperator(ch)) {
                while (!stack.isEmpty() && stack.peek() != '(' && _prec(stack.peek()) >= _prec(ch)) {
                    res += stack.pop();
                }
                stack.push(ch);
            }
            else{
                res += ch;
            }
        }

        return res;
        
    }

    static double calculateRPN(String rpn, double* args) {
        Stack<double> stack;

        for (int i = 0; i < rpn.getLength(); i++) {
            char ch = rpn[i];

            if (ch == '\0' || ch == ' ') continue;

            if (_isOperator(ch)) {
                // Pop the top two operands
                // Note: Second pop is the left operand (a), first pop is the right (b)
                double val2 = stack.pop();
                double val1 = stack.pop();

                // Calculate and push result back
                stack.push(_applyOp(val1, val2, ch));
            }
            else {
                stack.push(args[_getIndex(ch)]);
            }
        }

        // The final result is the only item left on the stack
        return stack.pop();
    }
};

int main()
{
    const int argc = 5;

    String infix, postfix;
    double* args = new double[argc];

    std::cout << "Enter an infix expression: ";
    infix.readFromStream(std::cin);

    postfix = RPN::getPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    std::cout << "Enter a,b,c,d,e(space separated): ";

    for (int i = 0; i < argc; i++)
    {
        std::cin >> args[i];
    }

    std::cout << "Calculation result: " << RPN::calculateRPN(postfix, args);
}