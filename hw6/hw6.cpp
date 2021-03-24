#include <iostream>

using namespace std;



int Parent(int i) { return (i - 1) / 2; }
int LeftChild(int i) { return 2 * i + 1; }
int RightChild(int i) { return 2 * i + 2; }


struct MaxHeap
{
    int* array;
    int size;
    int maxSize;



    void SiftUp(int i)
    {
        while (i > 0 & array[i] > array[Parent(i)])
        {
            int time = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = time;
        }
    }
    void SiftDown(int i)
    {
        if (array[i] > array[LeftChild(i)] & array[i] > array[RightChild(i)])
            return ;

        if (array[i] < array[LeftChild(i)])
        {
            int time = array[i];
            array[i] = array[LeftChild(i)];
            array[LeftChild(i)] = time;
            return ;
        }

        if (array[i] < array[RightChild(i)])
        {
            int time = array[i];
            array[i] = array[RightChild(i)];
            array[RightChild(i)] = time;
            return ;
        }
    }
    void Insert(int p)
    {
        if (size < maxSize)
        {
            size++;
            array[size] = p;
            SiftUp(size);
        }
    }
    int ExtractMax()
    {
        int result = array[0];
        int time = array[0];
        array[0] = array[size];
        array[size] = time;
        size--;

        SiftDown(0);
        return result;
    }
    int GetMax()
    {
        int time = array[size-1];
        delete[] array[size - 1];
        size--;

        SiftDown(0);
        return time;
    }
};
