#include <iostream>
#include "cmath"
using namespace std;



void task1(){
    int first;
    int last;
    int x;
    int size;
    int numbers;
    int i = 0;
    cout<<"write x"<<endl;
    cin>>x;
    cout<<"write size of array"<<endl;
    cin>>size;
    cout<<"write array"<<endl;
    cin>>numbers;
    int array[size];
    int rev_array[size];
    while (numbers>0){
        array[i] = numbers % 10;
        numbers = numbers / 10;
        i++;
    }
    for (int i=0, j=size-1; i<size; i++, j-- ){
        rev_array[i]=array[j];
    }
    //for (int i = 0; i<size;i++){
      //  cout<<rev_array[i]<<endl;
    //}
    if (size%2==0){
        int center = size/2;
        int right = size;
        int left = 0;
        while (0<1) {
            if (rev_array[center] == x) {
                first = center;
                last = center;
                while (rev_array[first - 1] == x and first - 1 > -1) {
                    first--;
                   // cout<<'f'<<endl;
                }
                while (rev_array[last + 1] == x and last +1 < size) {
                    //cout<<'l'<<endl;
                    last++;
                }
                break;
            }
            if (rev_array[center] > x) {
                right = center;
                center = left+(right-left)/2;
                //cout<<1<<endl;
                continue;
            }
            if (rev_array[center] < x) {
                left = center;
                center = left+(right-left)/2;
                //cout<<2<<endl;
                continue;
            }
        }
    }
    if (size%2!=0){
        int center = size/2;
        int right = size;
        int left = 0;
        while (0<1) {
            if (rev_array[center] == x) {
                first = center;
                last = center;
                while (rev_array[first - 1] == x and first - 1 > -1) {
                    first--;
                    //cout<<'f'<<endl;
                }
                while (rev_array[last + 1] == x and last +1 < size+1) {
                    //cout<<'l'<<endl;
                    last++;
                }
                break;
            }
            if (rev_array[center] > x) {
                right = center;
                center = left+(right-left)/2;
                //cout<<1<<endl;
                continue;
            }
            if (rev_array[center] < x) {
                left = center;
                center = left+(right-left)/2;
                //cout<<2<<endl;
                continue;
            }
        }
    }
    cout<<first<<endl;
    cout<<last<<endl;
};
void task3(){
    int x;
    cout<<"write number"<<endl;
    cin>>x;
    int left = 0;
    int right = x;
    int center = x/2;
    while ((center)*(center)<=x ||pow(center,2)>x){
        //cout<<center<<endl;
        if (center*center==x)
            break;
        if (pow(center,2)<x && pow(center+1,2)>=x){
            center++;
            break;
        }
        if (pow(center+1,2)==x){
            center++;
            break;
        }
        if (center*center<x){
            left = center;
            center = left+(right-left)/2;
            //cout<<1;
            continue;
        }
        if (center*center>x){
            right = center;
            center = left+(right-left)/2;
            //cout<<2;
            continue;
        }

        cout<<center<<endl;

    }
    if (abs((center-1)*(center-1)-x) < abs(center*center-x))
        cout<< center-1<<endl;
    else
        cout<<center<<endl;
};

int main() {
    //task1();
    task3();
    return 0;
}
