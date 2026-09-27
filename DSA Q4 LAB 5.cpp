#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

// Convert infix to postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // Operand: x or number
        if (ch == 'x' || isdigit(ch))
        {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        // Operator
        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Empty remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}


// Evaluate postfix
double evaluatePostfix(string postfix, double x)
{
    stack<double> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // x
        if (ch == 'x')
        {
            s.push(x);
        }

        // Number
        else if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // Operator
        else
        {
            double b = s.top();
            s.pop();

            double a = s.top();
            s.pop();

            if (ch == '+')
                s.push(a + b);

            else if (ch == '-')
                s.push(a - b);

            else if (ch == '*')
                s.push(a * b);

            else if (ch == '/')
                s.push(a / b);

            else if (ch == '^')
                s.push(pow(a, b));
        }
    }

    return s.top();
}


int main()
{
    string expression1, expression2;
    double x;

    cout << "Enter Expression 1: ";
    getline(cin, expression1);

    cout << "Enter Condition 1: x >= 0" << endl;

    cout << "Enter Expression 2: ";
    getline(cin, expression2);

    cout << "Enter Condition 2: x < 0" << endl;

    cout << "Enter x: ";
    cin >> x;

    cout << "\nTherefore, Piecewise Function is\n";

    cout << "f(x) = {\n";
    cout << "    " << expression1 << ", if x >= 0\n";
    cout << "    " << expression2 << ", if x < 0\n";
    cout << "}\n";


    // Check which condition is satisfied
    string selectedExpression;
    string selectedCondition;

    if (x >= 0)
    {
        selectedExpression = expression1;
        selectedCondition = "x >= 0";
    }
    else
    {
        selectedExpression = expression2;
        selectedCondition = "x < 0";
    }


    // Convert selected expression to postfix
    string postfix = infixToPostfix(selectedExpression);

    // Evaluate postfix
    double result = evaluatePostfix(postfix, x);


    cout << "\nThe program selects:\n";
    cout << "Condition: " << selectedCondition << endl;
    cout << "Expression: " << selectedExpression << endl;
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Calculated Value: " << result << endl;

    return 0;
}
