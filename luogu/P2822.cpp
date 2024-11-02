#include<bits/stdc++.h>
using namespace std;

int t, k, n, m;
long long san[2005][2005], ans[2005][2005];

void build(){
    san[0][0] = 1;
    san[1][0] = san[1][1] = 1;
    for(int i = 2; i <= 2003; i++){
        san[i][0] = 1;
        for(int j = 1; j <= i; j++){
            san[i][j] = (san[i - 1][j - 1] + san[i - 1][j]) % k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if(!san[i][j]) ans[i][j]++;
        }
        ans[i][i + 1] = ans[i][i];
    }
}

int main(){
    cin >> t >> k;
    build();
    while(t--){
        cin >> n >> m;
        if(m > n) cout << ans[n][n] << endl;
        else cout << ans[n][m] << endl;
    }
    return 0;
}