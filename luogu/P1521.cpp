#include<bits/stdc++.h>
using namespace std;
const int mod = 10000;

int n, k, dp[105][10005];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= k; j++){
            for(int z = max(j - i + 1, 0); z <= j; z++){
                dp[i][j] = (dp[i][j] + dp[i - 1][z]) % mod;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}