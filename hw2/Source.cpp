#include <iostream>

using namespace std;

int sum(int * a, int size)
{
    int x = 0;
    for (int i = 0; i < size; i++)
        x += *(a+i);
    return x;
}


void second_task()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "введите количество элементов массива:";
	cin >> n;
	int* x = new int[n];
	int* sum = new int[n * 2];

	cout << "введите элемент массива: ";
	for (int i = 0; i < n; i++)
	{
				cin >> *(x + i);
	}

	for (int i = 0; i < n; i++)
		*(sum + i) = *(x + i);

	delete[] x;

	int* y = new int[n];

	cout << "введите элемент массива: ";
	for (int i = 0; i < n; i++)
	{
				cin >> *(y + i);
	}


	for (int i = 0; i < n; i++)
		*(sum + n + i) = *(y + i);

	delete[] y;

	for (int i = 0; i < n * 2; i++)
		cout << *(sum + i);

}


void sort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(a+j) > *(a+j+1))
			{
				int val = *(a + j) ;
				*(a + j) = *(a + j  +1);
				*(a + j + 1) = val;
			}
		}
	}
	for (int i = 0; i < size; i++)
		cout << *(a + i);
}

int main()
{
    int m[5] = { 5, 4, 1, 2, 0 };
    cout << sum(m, 5) << "\n";
    second_task();
	cout << "\n";
	sort(m, 5);
    return 0;
}

