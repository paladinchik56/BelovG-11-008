#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a, b, c, D, x1, x2;
    cin >> a >> b >> c;
    D = pow(b,2) - 4 * a * c;
    if (D > 0){
        D = sqrt(D);
        cout << (-b - D)/2/a << endl;
        cout << (-b + D)/2/a ;
    };
    if (D == 0){
        cout << -b/2/a;
    };
    if (D < 0){
        cout << "Корней нет";
    };

    return 0;
}

