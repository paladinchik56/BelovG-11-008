#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x = 0, p;
    cin >> p;

    while(pow(2,x) < p){
        x += 1;
    };
    cout << x-1;
    return 0;
}
