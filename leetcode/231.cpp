#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    if(n > 0 && (n & (-n)) == n) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}