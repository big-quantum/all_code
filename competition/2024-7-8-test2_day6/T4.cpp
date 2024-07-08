#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, a[505];

int main(){
    freopen("T4.in", "r", stdin);
    freopen("T4.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    long long ans = 1;
    for(int i = 1; i <= n - m; i++){
        ans = ans * 2 % mod;
    }
    cout << ans << endl;
    return 0;
}
