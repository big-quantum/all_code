#include<bits/stdc++.h>
using namespace std;

int n, q, st[50005][20][2], log_2[50005];

void init(){
    for(int i = 2; i <= n; i++){
        log_2[i] = log_2[i / 2] + 1;
    }
    for(int i = 1; i <= log_2[n]; i++){
        for(int j = 1; j <= n - (1 << i) + 1; j++){
            st[j][i][0] = max(st[j][i - 1][0], st[j + (1 << (i - 1))][i - 1][0]);
            st[j][i][1] = min(st[j][i - 1][1], st[j + (1 << (i - 1))][i - 1][1]);
        }
    }
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> st[i][0][0];
        st[i][0][1] = st[i][0][0];
    }
    init();
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        cout << max(st[a][log_2[b - a + 1]][0], st[b - (1 << log_2[b - a + 1]) + 1][log_2[b - a + 1]][0]) - min(st[a][log_2[b - a + 1]][1], st[b - (1 << log_2[b - a + 1]) + 1][log_2[b - a + 1]][1]) << endl;
    }
    return 0;
}