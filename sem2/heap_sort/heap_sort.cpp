#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void double_heat(int *arr, int size, int i, long * iter)
{
    (*iter)++;

    int the_smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[the_smallest])
        the_smallest = left;

    if (right < size && arr[right] < arr[the_smallest])
        the_smallest = right;

    if (the_smallest != i)
    {
        swap(arr[i], arr[the_smallest]);
        double_heat(arr, size, the_smallest, iter);
        return;
    }

}

void heap_sort(int *arr, int n, long * iter)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        double_heat(arr, n, i, iter);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        double_heat(arr, i, 0, iter);
    }
}

void show(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{






    long iter = 0;
    for (int size = 2000; size < 1000001; size = size + 1000)
    {
        //этот отрекзок для чтения сгенерированных данных
        string path = "/home/grigoriy/univer/BelovG-11-008/sem2/heap_sort/100000000.txt";
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
        heap_sort(arr, size, &iter);
        unsigned int end_time = clock();

        cout << iter<< endl;
    }
    // cout <<end_time - start_time<<endl;
    //cout << iter<< endl;
    //show(arr, size);
    return 0;

}