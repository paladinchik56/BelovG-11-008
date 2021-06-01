#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

void show(int array[], int len_array)
{
    for (int i = 0; i < len_array; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int array[], int length, long * iter)
{
    for (int i = 0; i < length; i++)
    {
        (*iter)++;
        for (int j = 0; j < length-1-i; j++)
        {
            if (array[j]>array[j+1])
                swap(array[j], array[j+1]);
        }
    }
}


int main() {
    long iter = 0;
    for (int size = 1; size < 10002; size = size + 100)
    {
        //этот отрекзок для чтения сгенерированных данных
        string path = "/home/grigoriy/univer/BelovG-11-008/sem2/bubble_sort/data.txt";
        int arr[size];
        ifstream fin;
        fin.open(path);
        //проверка, считало ли файл
        if (!fin)
            cout<<11<< endl;
        for (int i = 0; i<size; i++)
        {
            int x;
            //cout << x << " ";
            fin >> x;
            arr[i] = x;
        }
//
        unsigned int start_time =  clock();
        bubble_sort(arr, size, &iter);
        unsigned int end_time = clock();

        cout << iter<< endl;;
    }
    // cout <<end_time - start_time<<endl;
    //cout << iter<< endl;
    //show(arr, size);

    return 0;
}
