#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int t, a, b, c;

int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        long long ans = 0;
        if(c > max(a, b) + 1){
            cout << ans << endl;
            continue;
        }
        if(a > b) swap(a, b);
        if(a != b){


            cout << ans % mod << endl;
        } else {


            cout << ans % mod<< endl;
        }
    }


    return 0;
}
