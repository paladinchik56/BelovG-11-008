#include <iostream>

using namespace std;

int main()
{
    int i, x, sum = 0;
    cin >> i;
    while (i != 0) {
        i -= 1;
        cin >> x;
        sum += x;
    }
    cout << sum;

    return 0;
}
