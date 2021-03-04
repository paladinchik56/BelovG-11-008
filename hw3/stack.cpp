#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node * next;
};

struct Stack
{
    Node * pHead;

    void Push(int x)
    {
        Node * node = new Node;
        node->item = x;
        node->next = pHead;
        pHead = node;
    }

    int Pop()
    {
        if (!pHead)
            throw 1;

        Node* temp = pHead;
        int x = temp->item;
        pHead = temp->next;
        delete temp;
        return x;
    }

    int Peek()
    {
        if (!pHead)
            throw 1;

        return pHead->item;
    }
    void printAll()
    {
        while (pHead)
        {
            Node* temp = pHead;
            int x = temp->item;
            pHead = temp->next;
            cout << x << endl;
            delete temp;
        };
        

    }
};


int main()
{
    Stack* stack = new Stack;

    stack->Push(10);
    stack->Push(20);

    stack->printAll();

    //cout << stack->Pop() << endl;
    //cout << stack->Pop() << endl;

    delete stack;
    return 0;
}
