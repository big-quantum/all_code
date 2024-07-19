#include<bits/stdc++.h>
using namespace std;

int n, k, dp[505][105];
pair<int, int> point[505];
int dis(int a, int b){
    return point[b].first - point[a].first + point[b].second - point[a].second - 1;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> point[i].first >> point[i].second;
    }
    sort(point + 1, point + 1 + n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = j + 1;
        }
    }
    for (int i = 2; i <= n; i++){
        for(int j = i - 1; j >= 1; j--){
            if(point[j].second > point[i].second) continue;
            for(int z = dis(j, i); z <= k; z++){
                
                dp[i][z] = max(dp[i][z], dp[j][z - dis(j, i)] + dis(j, i) + 1);
            }
        }
    }
    int maxn = -1;
    for(int i = 1; i <= n; i++) maxn = max(maxn, dp[i][k]);
    cout << maxn << endl;

    return 0;
}