#include<bits/stdc++.h>
using namespace std;

int t, n, a[300005], dp[300005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            dp[i] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = max(0, i - 400); j < i; j++){
                if((a[i] ^ j) > (a[j] ^ i) && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
            dp[i] = 0;
        }
        cout << ans << endl;
    }


    return 0;
}