#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node* head;
    List()
    {
        head = NULL;
    }

    void add(int item)
    {
        Node* temp = new Node;
        temp->data = item;
        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else
        {
            Node* step = head;
            while (step->next != NULL)
            {
                step = step->next;
            };
            step->next = temp;
        }
    }
    int size()
    {
        if (head == NULL)
            return 0;
        else
        {
            
            int i = 1;
            for (Node* temp = head; temp->next != NULL; i++)
            {
                temp = temp->next;
            }
            return i;
        }


    }
    struct Node get(int id)
    {
        if (head != NULL)
        {
            Node* temp = head;
            for (int i = 0; i < id; i++)
            {
                temp = temp->next;
            }
            return *temp;
        }
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
                cout << temp << endl;
                temp = temp->next;
            }
            cout << temp << endl;
        }   
    }
};


int main()
{
    List* list = new List;
    list->add(10);
    list->add(1);
    list->add(3);
    cout << list->size() <<endl;
    list->printAll();

    return 0;
}