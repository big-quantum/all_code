#include<bits/stdc++.h>
using namespace std;

int n, m, k, cntt, a[10005], b[10005];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == k) cnt++;
        }
        if(cnt >= n / 2 + n % 2) cntt++;
    }
    if(cntt >= m / 2 + m % 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}