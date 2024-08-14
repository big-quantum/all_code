#include<bits/stdc++.h>//找找规律
using namespace std;
long long n, m, a[105][105], dp[2][105];
int main(){
    freopen("outfit.in", "r", stdin);
    freopen("outfit.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    bool flag = false;
    for(int i = 2; i <= n + 1; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                dp[flag][j] = max(dp[flag][j], dp[!flag][k] + a[j][k]);
            }
        }
        flag = !flag;
    }
    int ans = INT_MIN;
    for(int i = 1; i <= m; i++){
        ans = max(ans, dp[!flag][i]);
        
    }
    cout << ans << endl;
    return 0;
}
/*
9 3 1 
12 4 4 
13 7 5 
13

*/