#include <iostream>

using namespace std;
int power(int x, unsigned p)
{
    int i = 1, x1 = x;

    while (i != p)
    {
        i += 1;
        x1 *= x;
    }
    return x1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << power(n, m);
    return 0;
}