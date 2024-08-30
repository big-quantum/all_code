#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, a[505];
//区间动态规划：
//状态： dp[l][r][k] 已经插入k个整数，要求后续所有要插入的整数都插入到[0, l]或[r, m + 1]的方案数
//状态转移：从小到大枚举插入的数字T
//
//
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
