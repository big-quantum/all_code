#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(){
    cin >> a >> b >> c >> d;
    if(a == 0 && c == 0){
        cout << b / d << endl;
        return 0;
    }
    if(b == 0 && d == 0){
        cout << a / c << endl;
        return 0;
    }
    if(a / c != b / d) cout << -1 << endl;
    else cout << a / c << endl;
    return 0;
}