#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int d[105][2];
int dp[1005][505];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> d[i][0] >> d[i][1];
    }

    for(int i = 1; i <= k; i++){
        for(int j = n; j >= d[i][0]; j--){
            for(int x = m; x >= d[i][1]; x--)
                dp[j][x] = max(dp[j][x], dp[j - d[i][0]][x - d[i][1]] + 1);
        }
    }
/*
    for(int j = 1; j <= n; j++){
            for(int x = 1; x <= m; x++)
                cout << dp[j][x] << " ";
            cout << endl;
        }*/
    
    return 0;
}