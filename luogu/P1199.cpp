#include<bits/stdc++.h>
using namespace std;

int n, attrack[505][505], maxx = -1;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> attrack[i][j];
            attrack[j][i] = attrack[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(attrack[i], attrack[i] + n + 1);
        maxx = max(maxx, attrack[i][n - 1]);
    }
    cout << 1 << endl;
    cout << maxx << endl;

    return 0;
}