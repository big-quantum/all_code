#include<bits/stdc++.h>//65
using namespace std;
const long long mod = 1e9 + 7;

int n, k, flag[200005];
map<int, int> p;
long long a[200005], num[200005], dp[200005];

void dfs(int to, int k, int pos, int val){
    if(k == 0){
        
    }
}

int main(){
    freopen("medal.in", "r", stdin);
    freopen("medal.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        num[i] = num[i - 1] + a[i];
    }
    //submit 1
    if(k == 1){
        long long maxn = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i], dp[i - 1] + a[i]);
            maxn = max(dp[i], maxn);
        }
        cout << (maxn + num[n]) % mod << endl;
        return 0;
    }
    //submit 2
    if(n == 2){
        if(a[1] + a[2] > 0 && k > 1){
            long long ans = a[1] + a[2];
            while(k--){
                ans += ans;
                ans %= mod;
            }
            cout << ans % mod << endl;
            return 0;
        } else {
            cout << (a[1] + a[2]) % mod << endl;
            return 0;
        }
    }
    //submit3
    long long ans = num[n];
    while(k--){
        ans += ans;
        ans %= mod;
    }
    cout << ans % mod << endl;
    //submit4
    return 0;
}