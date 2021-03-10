#include <iostream>

using namespace std;

struct Node
    {
        int data;
        Node* next, * back;
    };

struct Dlinked_list
{
    Node* head;
    Dlinked_list()
    {
        head = NULL;
    };
    
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
            Node* old = NULL;
            while (step->next != NULL)
            {
                step = step->next;
            };
            step->next = temp;
            temp->back = step;
        };
    };
    int get(int id)
    {
        Node* temp = head;
        if (head != NULL)
        {
            for (int i = 0; i < id; i++)
            {
                temp = temp->next;
            }
            return temp->data;
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
    void insertAt(int item, int id)
    {
        Node* temp = head;
        Node* time = new Node;
        Node* old = new Node;
        time->data = item;
        for (int i = 0; i < id; i++)
        {
            temp = temp->next;

        }
        old = temp;
        temp = time;
        time->next = old->next;
        temp->back = old;
        old->next = time;
    }
    void removeAt(int id)
    {   
        Node* time = new Node;
        Node* temp = head;
        for (int i = 0; i < id; i++)
        {
            temp = temp->next;
        }
        time = temp->next;
        temp = temp->back;
        temp->next = time;
    }
};
    


int main()
{
    Dlinked_list* list = new Dlinked_list;
    list->add(10);
    list->add(3);
    list->add(11);
    list->printAll();
    return 0;
};