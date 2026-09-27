#include <iostream>
#include <string>

using namespace std;

#define MAX 100

// Stack using array
class Stack
{
    string arr[MAX];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(string value)
    {
        if (top < MAX - 1)
        {
            arr[++top] = value;
        }
    }

    string pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }

        return "";
    }

    bool empty()
    {
        return top == -1;
    }
};


// Generate arithmetic series
string generateSeries(int n)
{
    string series = "";

    for (int i = 1; i <= n; i++)
    {
        int term = 3 * i - 2;

        series += to_string(term);

        if (i < n)
        {
            series += " + ";
        }
    }

    return series;
}


// Generate postfix using stack
string generatePostfix(int n)
{
    string postfix = "";

    for (int i = 1; i <= n; i++)
    {
        int term = 3 * i - 2;

        postfix += to_string(term);
        postfix += " ";

        if (i > 1)
        {
            postfix += "+ ";
        }
    }

    return postfix;
}


// Generate prefix using our own stack
string generatePrefix(int n)
{
    Stack operands;
    Stack operators;

    // Push all operands
    for (int i = 1; i <= n; i++)
    {
        int term = 3 * i - 2;

        operands.push(to_string(term));

        if (i > 1)
        {
            operators.push("+");
        }
    }

    // Combine using stack
    while (!operators.empty())
    {
        string op = operators.pop();

        string right = operands.pop();
        string left = operands.pop();

        string result = op + " " + left + " " + right;

        operands.push(result);
    }

    return operands.pop();
}


int main()
{
    int n;

    cout << "Enter number of terms n: ";
    cin >> n;

    string series = generateSeries(n);

    string postfix = generatePostfix(n);

    string prefix = generatePrefix(n);

    cout << "\nSeries: " << series << endl;

    cout << "Postfix: " << postfix << endl;

    cout << "Prefix: " << prefix << endl;

    return 0;
}
