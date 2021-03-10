#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next, * back;
};

struct Queue
{
    Node* head;
    Node* end;
    Queue()
    {
        end = NULL;
        head = NULL;
    };

    void Enqueue(int item)
    {
        Node* temp = new Node;
        temp->data = item;
        temp->next = NULL;
        Node* time = new Node;
        if (head == NULL)
            head = temp;

        else
        {
            temp->next = head;
            head->back = temp;
            time = head;
            head = temp;
            temp = time;
            delete time;
        };
    };
    int Dequeue()
    {
        if (head == NULL)
            cout << "Queue is let" << endl;
        else
        {
            Node* step = head;
            Node* end = NULL;
            Node* time = NULL;
            while (step->next != NULL)
            {
                step = step->next;
            };
            end = step->back;
            time = step;
            step = NULL;
            return time->data;
        };
    }
    void printAll()
    {
        Node* temp = head;
        if (head == NULL)
            cout << "list is let" << endl;
        else
        {
            while (temp->next != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
};



int main()
{
    Queue* list = new Queue;
    list->Enqueue(10);
    list->Enqueue(1);
    list->Enqueue(3);
    list->printAll();
    cout << list->Dequeue() << endl;

    return 0;
};