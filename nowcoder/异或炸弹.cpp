#include<bits/stdc++.h>
using namespace std;

int cf[3005][3005], n, m, ans = 0;

void change(int x, int y, int r){
    for(int i = x - r; i <= x + r; i++){
        if(i < 1) continue;
        if(i > n) break;
        int l = r - abs(x - i);
        cf[max(1, y - l)][i] ^= 1;
        cf[min(n + 1, y + l + 1)][i] ^= 1;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){    
        int x, y, r;
        cin >> x >> y >> r;
        change(x, y, r);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cf[j][i] ^= cf[j - 1][i];
            if(cf[j][i] & 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}