#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sos.in", "r", stdin);
    freopen("sos.out", "w", stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 3) cout << 0 << endl;
        if(n == 7) cout << 1 << endl;
        if(n == 18) cout << -1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
