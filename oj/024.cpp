#include<bits/stdc++.h>
using namespace std;

int n, k, profit[105], group[105], minprofit;
int dp[105][105][105], ans;
const int maxn = 1e9 + 7;

int main(){
    cin >> n >> k >> minprofit;
    for(int i = 1; i <= k; i++) {
        cin >> group[i] >> profit[i];
    }

    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i >= group[j]){
                dp[i][j] = max(dp[i - 1][j], dp[i - group[j]][j - 1] + profit[j]);
            }
            if(dp[i][j] != dp[i - 1][j] && dp[i][j] >= minprofit) {
                ans++;
                ans = ans % maxn;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}