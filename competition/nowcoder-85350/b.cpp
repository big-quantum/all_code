#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long w, n = 1, d, p, q, ans;

long long quick_pow(long long a, int p){
    long long ans = 1;
    while(p != 0){
        ans *= a * (p & 1) % mod;
        p >>= 1;
        a *= a % mod;
    }
    return ans;
}

int main(){
    cin >> w >> d;
    ans = 1;
    for(int i = 1; i <= w; i++){
        cin >> p >> q;
        n *= quick_pow(p, q) % mod;
        ans += quick_pow(p, q * d % mod) % mod; 
    }
    ans += quick_pow(n, d) % mod;
    cout << ans % mod << endl;
    return 0;
}
