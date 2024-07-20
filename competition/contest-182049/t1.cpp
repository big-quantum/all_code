#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
    cin >> a >> b;
    a = a / 10;
    b = b * 10;
    c = 10000 - a - b;
    cout << a << " " << b << " " << c << endl;

    return 0;
}