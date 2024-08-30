#include<bits/stdc++.h>
using namespace std;

int n, m, l, r, f, t;
long long s[10000005];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d%d", &l, &r, &f, &t);
        int d = (t - f) / (r - l);
        s[l] += f;
        s[l + 1] += d - f;
        s[r + 1] -= t + d;
        s[r + 2] += t;
    }
    long long ans = 0, s1 = 0, heat = 0, maxn = 0;
    for(int i = 1; i <= n; i++){
        heat += s[i];
        s1 += heat;
        if(ans) ans ^= s1;
        else ans = s1;
        if(s1 > maxn) maxn = s1;
    }
    cout << ans << " " << maxn;

    return 0;
}