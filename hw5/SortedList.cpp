#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = 0;
};

struct Sorted_List
{
    Node* head;
    Sorted_List()
    {
        head = NULL;
    }

    void add(int item)
    {
        Node* temp = new Node;
        temp->data = item;
        temp->next = head;

        head = temp;

        Node* step = head;
        while (step->next != NULL)
        {
            if (step->data > step->next->data)
            {
                int buff = step->data;
                step->data = step->next->data;
                step->next->data = buff;
            }
            step = step->next;
        };
    }
    int get(int id)
    {
        Node* step = new Node;
        step = head;
        for (int i = 0; i < id; i++)
        {
            step = step->next;
        }
        return step->data;
    };
    void remove(int id)
    {
        Node* step = new Node;
        step = head;
        if (id == 0)
        {
            head = head->next;
        }
        else
        {
        for (int i = 0; i < id-1; i++)
        {
            step = step->next;
        }
        step->next = step->next->next;
        }
    };

    void printAll()
    {
        Node* temp = head;
        if (head == NULL)

            cout << "List is empty" << endl;
        else
        {
            while (temp->next != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << temp->data << endl;
            cout << "List is over" << endl;
        }
    };

};
int main()
{
    Sorted_List* list = new Sorted_List;
    list->add(1);
    list->add(3);
    list->add(2);
    list->add(5);
    list->add(4);
    list->add(0);
    cout << list->get(5)<< endl;
    list->remove(5);
    list->printAll();
    return 0;
}