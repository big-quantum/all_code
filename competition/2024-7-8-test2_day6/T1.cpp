#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int t, a1, a2, a3;

long long ans1[4000005][2];
long long dfs1(int n, bool flag){
    if(ans1[n][flag] != 0 && n < 4000000) return ans1[n][flag];
    if(n == 1)
        if(flag) ans1[n][flag] = 27;
        else ans1[n][flag] = 36;
    else 
        if(flag) ans1[n][flag] = (dfs1(n - 1, false) * 35 % mod + dfs1(n - 1, true) * 65 % mod) % mod;
        else ans1[n][flag] = (dfs1(n - 1, false) * 45 % mod + dfs1(n - 1, true) * 55 % mod) % mod;
    return ans1[n][flag];
}
long long ans2[4000005][2];
long long dfs2(int n, bool flag){
    if(ans2[n][flag] != 0 && n < 4000000) return ans2[n][flag];
    if(n == 1)
        if(flag) ans2[n][flag] = 55;
        else ans2[n][flag] = 45;
    else 
        if(flag) ans2[n][flag] = (dfs1(n - 1, false) * 35 % mod + dfs1(n - 1, true) * 65 % mod) % mod;
        else ans2[n][flag] = (dfs1(n - 1, false) * 45 % mod + dfs1(n - 1, true) * 55 % mod) % mod;
    return ans2[n][flag];
}
long long ans3[4000005][2];
long long dfs3(int n, bool flag){
    if(ans3[n][flag] != 0 && n < 4000000) return ans3[n][flag];
    if(n == 1)
        if(flag) ans3[n][flag] = 54;
        else ans3[n][flag] = 45;
    else 
        if(flag) ans3[n][flag] = (dfs1(n - 1, false) * 35 % mod + dfs1(n - 1, true) * 65 % mod) % mod;
        else ans3[n][flag] = (dfs1(n - 1, false) * 45 % mod + dfs1(n - 1, true) * 55 % mod) % mod;
    return ans3[n][flag];
}
int main(){
    freopen("T1.in", "r", stdin);
    freopen("T1.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> a1 >> a2 >> a3;
        if(a1 > a2) swap(a1, a2);
        if(a3 - a2 > 1){
            cout << 0 << endl;
            continue;
        }
        if(a1 == a2 && a2 == a3){
            cout << dfs1(a1, false) << endl;
            continue;
        }
        if(a3 - a2 == 1 && a2 > a1){
            cout << dfs2(a1, false) << endl;
            continue;
        }
        if(a3 - a2 == 1 && a2 == a1){
            cout << dfs3(a1, false) << endl;
            continue;
        }
    }
    return 0;
}