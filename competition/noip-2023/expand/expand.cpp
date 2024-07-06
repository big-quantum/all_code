#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50005;

int c, n, m, q, x[MAXN], y[MAXN];

int main() {
    freopen("expand.in", "r", stdin);//remember to change
    freopen("expand.out", "w", stdout);
    
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &y[i]);
    }
    bool flag1 = true, flag2 = true;
    int maxn = 0;
    //priority_queue<int> que;
    for(int i = 1; i <= max(m, n); i++) {
        if(i <= n) maxn = max(maxn, x[i]);
        if(y[i] > maxn){
            flag1 = false;
            break;
        }
    }
    maxn = 0;
    for(int i = 1; i <= max(m, n); i++) {
        if(i <= m) maxn = max(maxn, y[i]);
        if(x[i] > maxn){
            flag2 = false;
            break;
        }
    }

    if(flag1 || flag2) printf("1");
    else printf("0");

    while(q > 0) {
        q--;
        int kx, ky;
        int p[MAXN][3];
        scanf("%d%d", &kx, &ky);
        for(int i = 1; i <= kx; i++) {
            scanf("%d%d", &p[i][0], &p[i][1]);
            p[i][2] = x[p[i][0]];
            x[p[i][0]] = p[i][1];
        }
        for(int i = 1 + kx; i <= kx + ky; i++) {
            scanf("%d%d", &p[i][0], &p[i][1]);
            p[i][2] = y[p[i][0]];
            y[p[i][0]] = p[i][1];
        }
        flag1 = true;
        flag2 = true;
        maxn = 0;

        for(int i = 2; i <= max(m, n); i++) {
            if(i <= n) maxn = max(maxn, x[i]);
            if(y[i] > maxn){
                flag1 = false;
                break;
            }
        }
        maxn = 0;
        for(int i = 2; i <= max(m, n); i++) {
            if(i <= m) maxn = max(maxn, y[i]);
            if(x[i] > maxn){
                flag2 = false;
                break;
            }
        }

        if(flag1 || flag2) printf("1");
        else printf("0");

        for(int i = 1; i <= kx; i++) {
            x[p[i][0]] = p[i][2];
        }
        for(int i = 1 + kx; i <= kx + ky; i++) {
            y[p[i][0]] = p[i][2];
        }
    }
    
    return 0;
}