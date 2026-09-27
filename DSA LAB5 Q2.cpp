#include <iostream>
using namespace std;

// ================= STACK NODE =================

struct Node
{
    int data;
    Node* next;
};

// ================= PUSH =================

void push(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    // Since first entered element is bottom,
    // insert new elements at the END.
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// ================= DISPLAY =================

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// ================= CREATE STACK 3 =================

void createStack3(Node* head1, Node* head2, Node*& head3)
{
    while (head1 != NULL && head2 != NULL)
    {
        // Take one element from Stack 1
        push(head3, head1->data);
        head1 = head1->next;

        // Take one element from Stack 2
        push(head3, head2->data);
        head2 = head2->next;
    }

    // Remaining elements of Stack 1
    while (head1 != NULL)
    {
        push(head3, head1->data);
        head1 = head1->next;
    }

    // Remaining elements of Stack 2
    while (head2 != NULL)
    {
        push(head3, head2->data);
        head2 = head2->next;
    }
}

// ================= SORT STACK 3 =================

void sortStack(Node* head)
{
    Node* pos1;
    Node* pos2;

    for (pos1 = head; pos1 != NULL; pos1 = pos1->next)
    {
        for (pos2 = pos1->next; pos2 != NULL; pos2 = pos2->next)
        {
            if (pos1->data > pos2->data)
            {
                int temp = pos1->data;
                pos1->data = pos2->data;
                pos2->data = temp;
            }
        }
    }
}

// ================= CIRCULAR QUEUE =================

#define SIZE 100

class CircularQueue
{
private:
    int arr[SIZE];
    int front;
    int rear;

public:

    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

// ================= MAIN =================

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    int n1, n2;
    int value;

    // ================= STACK 1 =================

    cout << "Enter number of elements in Stack 1: ";
    cin >> n1;

    cout << "Enter Stack 1 elements: ";

    for (int i = 0; i < n1; i++)
    {
        cin >> value;
        push(head1, value);
    }

    // ================= STACK 2 =================

    cout << "Enter number of elements in Stack 2: ";
    cin >> n2;

    cout << "Enter Stack 2 elements: ";

    for (int i = 0; i < n2; i++)
    {
        cin >> value;
        push(head2, value);
    }

    // ================= DISPLAY STACKS =================

    cout << "\nStack 1: ";
    display(head1);

    cout << "Stack 2: ";
    display(head2);

    // ================= CREATE STACK 3 =================

    createStack3(head1, head2, head3);

    cout << "\nStack 3 before sorting: ";
    display(head3);

    // ================= SORT =================

    sortStack(head3);

    cout << "Stack 3 after sorting: ";
    display(head3);

    // ================= CREATE CIRCULAR QUEUE =================

    CircularQueue q;

    Node* temp = head3;

    while (temp != NULL)
    {
        q.enqueue(temp->data);
        temp = temp->next;
    }

    // ================= DISPLAY QUEUE =================

    cout << "\nCircular Queue: ";
    q.display();

    return 0;
}
