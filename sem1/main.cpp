#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ctime"
using namespace std;
int n_keys = 5; //t*2 - 1 или макс количество ключей

struct Node
{
    bool leaf;
    int *key, size;
    Node **ptr;

    Node()
    {
        key = new int[n_keys];
        ptr = new Node *[n_keys + 1];
    }
};

struct BPTree
{
    Node *root = 0;
    Node *findParent(Node *cursor, Node *child)
    {
        Node *parent;
        if (cursor->leaf || (cursor->ptr[0])->leaf)
        {
            return NULL;
        }
        for (int i = 0; i < cursor->size + 1; i++)
        {
            if (cursor->ptr[i] == child)
            {
                parent = cursor;
                return parent;
            }
            else
            {
                parent = findParent(cursor->ptr[i], child);
                if (parent != NULL)
                    return parent;
            }
        }
        return parent;
    }
    BPTree()
    {
        root = NULL;
    }
    void search(int x)
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
        }
        else
        {
            Node *cursor = root;
            while (cursor->leaf == false)
            {
                for (int i = 0; i < cursor->size; i++)
                {
                    if (x < cursor->key[i])
                    {
                        cursor = cursor->ptr[i];
                        break;
                    }
                    if (i == cursor->size - 1)
                    {
                        cursor = cursor->ptr[i + 1];
                        break;
                    }
                }
            }
            for (int i = 0; i < cursor->size; i++)
            {
                if (cursor->key[i] == x)
                {
                    cout << "Found\n";
                    return;
                }
            }
            cout << "Not found\n";
        }
    }
    void insert(int x)
    {
        if (root == NULL)
        {

            root = new Node;
            root->key[0] = x;
            root->leaf = true;
            root->size = 1;
        }
        else
        {
            Node *cursor = root;
            Node *parent;
            while (cursor->leaf == false)
            {
                parent = cursor;
                for (int i = 0; i < cursor->size; i++)
                {
                    if (x < cursor->key[i])
                    {
                        cursor = cursor->ptr[i];
                        break;
                    }
                    if (i == cursor->size - 1)
                    {
                        cursor = cursor->ptr[i + 1];
                        break;
                    }
                }
            }
            if (cursor->size < n_keys)
            {
                int i = 0;
                while (x > cursor->key[i] && i < cursor->size)
                    i++;
                for (int j = cursor->size; j > i; j--)
                {
                    cursor->key[j] = cursor->key[j - 1];
                }
                cursor->key[i] = x;
                cursor->size++;
                cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
                cursor->ptr[cursor->size - 1] = NULL;
            }
            else
            {
                Node *newLeaf = new Node;
                int virtualNode[n_keys + 1];
                for (int i = 0; i < n_keys; i++)
                {
                    virtualNode[i] = cursor->key[i];
                }
                int i = 0, j;
                while (x > virtualNode[i] && i < n_keys)
                    i++;
                for (int j = n_keys + 1; j > i; j--)
                {
                    virtualNode[j] = virtualNode[j - 1];
                }
                virtualNode[i] = x;
                newLeaf->leaf = true;
                cursor->size = (n_keys + 1) / 2;
                newLeaf->size = n_keys + 1 - (n_keys + 1) / 2;
                cursor->ptr[cursor->size] = newLeaf;
                newLeaf->ptr[newLeaf->size] = cursor->ptr[n_keys];
                cursor->ptr[n_keys] = NULL;
                for (i = 0; i < cursor->size; i++)
                {
                    cursor->key[i] = virtualNode[i];
                }
                for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++)
                {
                    newLeaf->key[i] = virtualNode[j];
                }
                if (cursor == root)
                {
                    Node *newRoot = new Node;
                    newRoot->key[0] = newLeaf->key[0];
                    newRoot->ptr[0] = cursor;
                    newRoot->ptr[1] = newLeaf;
                    newRoot->leaf = false;
                    newRoot->size = 1;
                    root = newRoot;
                }
                else
                {
                    insertInternal(newLeaf->key[0], parent, newLeaf);
                }
            }
        }
    }
    void insertInternal(int x, Node *cursor, Node *child)
    {
        if (cursor->size < n_keys)
        {
            int i = 0;
            while (x > cursor->key[i] && i < cursor->size)
                i++;
            for (int j = cursor->size; j > i; j--)
            {
                cursor->key[j] = cursor->key[j - 1];
            }
            for (int j = cursor->size + 1; j > i + 1; j--)
            {
                cursor->ptr[j] = cursor->ptr[j - 1];
            }
            cursor->key[i] = x;
            cursor->size++;
            cursor->ptr[i + 1] = child;
        }
        else
        {
            Node *newInternal = new Node;
            int virtualKey[n_keys + 1];
            Node *virtualPtr[n_keys + 2];
            for (int i = 0; i < n_keys; i++)
            {
                virtualKey[i] = cursor->key[i];
            }
            for (int i = 0; i < n_keys + 1; i++)
            {
                virtualPtr[i] = cursor->ptr[i];
            }
            int i = 0, j;
            while (x > virtualKey[i] && i < n_keys)
                i++;
            for (int j = n_keys + 1; j > i; j--)
            {
                virtualKey[j] = virtualKey[j - 1];
            }
            virtualKey[i] = x;
            for (int j = n_keys + 2; j > i + 1; j--)
            {
                virtualPtr[j] = virtualPtr[j - 1];
            }
            virtualPtr[i + 1] = child;
            newInternal->leaf = false;
            cursor->size = (n_keys + 1) / 2;
            newInternal->size = n_keys - (n_keys + 1) / 2;
            for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++)
            {
                newInternal->key[i] = virtualKey[j];
            }
            for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++)
            {
                newInternal->ptr[i] = virtualPtr[j];
            }
            if (cursor == root)
            {
                Node *newRoot = new Node;
                newRoot->key[0] = cursor->key[cursor->size];
                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newInternal;
                newRoot->leaf = false;
                newRoot->size = 1;
                root = newRoot;
            }
            else
            {
                insertInternal(cursor->key[cursor->size], findParent(root, cursor), newInternal);
            }
        }
    }

    void display(Node *cursor)
    {
        if (cursor != NULL)
        {
            for (int i = 0; i < cursor->size; i++)
            {
                cout << cursor->key[i] << " ";
            }
            cout << endl;
            if (cursor->leaf != true)
            {
                for (int i = 0; i < cursor->size + 1; i++)
                {
                    display(cursor->ptr[i]);
                }
            }
        }
    }
    Node *getRoot()
    {
        return root;
    };
};

int main() {
    BPTree node;
    node.insert(1);
    node.insert(1);
    node.insert(25);
    node.insert(33);
    node.insert(4);
    node.insert(5);
    node.insert(44);
    node.insert(323);
    node.insert(100);
    node.display(node.getRoot());

    node.search(12);
}