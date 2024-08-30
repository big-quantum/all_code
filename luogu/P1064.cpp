#include<bits/stdc++.h>
using namespace std;

int n, m, w[65], p[65], dp[50005], q[65][3], qq, cnt;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> p[i] >> qq;
        p[i] *= w[i];
        if(!qq){
            q[i][0] = i;
        } else {
            if(!q[qq][1]) q[qq][1] = i;
            else q[qq][2] = i;
        }
    }
    for(int i = 1; i <= m; i++){
        if(!q[i][0]) continue;
        for(int j = n; j >= w[i]; j--){
            dp[j] = max(dp[j - w[i]] + p[i], dp[j]);
            if(j >= w[i] + w[q[i][1]])
            dp[j] = max(dp[j - w[i] - w[q[i][1]]] + p[i] + p[q[i][1]], dp[j]);
            if(j >= w[i] + w[q[i][2]])
            dp[j] = max(dp[j - w[i] - w[q[i][2]]] + p[i] + p[q[i][2]], dp[j]);
            if(j >= w[i] + w[q[i][1]] + w[q[i][2]])
            dp[j] = max(dp[j - w[i] - w[q[i][1]] - w[q[i][2]]] + p[i] + p[q[i][1]] + p[q[i][2]], dp[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}