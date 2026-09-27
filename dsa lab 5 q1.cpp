#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    int size()
    {
        return top + 1;
    }

    void findValues()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        // Maximum and minimum
        int maximum = arr[0];
        int minimum = arr[0];

        for (int i = 1; i <= top; i++)
        {
            if (arr[i] > maximum)
                maximum = arr[i];

            if (arr[i] < minimum)
                minimum = arr[i];
        }

        cout << "Maximum: " << maximum << endl;
        cout << "Minimum: " << minimum << endl;

        // Middle element
        int n = top + 1;

        if (n % 2 == 1)
        {
            // Odd number of elements
            int middle = n / 2;
            cout << "Middle element: " << arr[middle] << endl;
        }
        else
        {
            // Even number of elements
            int middle1 = (n / 2) - 1;
            int middle2 = n / 2;

            cout << "Middle elements: "
                 << arr[middle1] << " and "
                 << arr[middle2] << endl;
        }
    }
};

int main()
{
    Stack s;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        s.push(value);
    }

    s.findValues();

    return 0;
}
