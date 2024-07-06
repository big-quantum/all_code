#include<bits/stdc++.h>
using namespace std;

long long _next[500005][2], cnt = 1, val[500005], t, n, m, cntt, tmp;

void insert_string(long long n){
    long long cur = 1, s = n;
    for(int i = 31, bit = (s >> i) & 1; i >= 0; i--, bit = (s >> i) & 1){
        if(!_next[cur][bit]){
            _next[cur][bit] = ++cnt;
        }
        cur = _next[cur][bit];
    }
    val[cur] = n;
}

long long find_string(long long n){
    long long cur = 1, s = n;
    for(int i = 31, bit = (s >> i) & 1; i >= 0; i--, bit = (s >> i) & 1){
        if(_next[cur][bit ^ 1]) cur = _next[cur][bit ^ 1];
        else cur = _next[cur][bit];
    }
    return val[cur];
}

int main(){              
    scanf("%lld", &t);
    while(t--){
        memset(_next, 0, sizeof(_next));
        memset(val, 0, sizeof(val));
        cout << "Case #" << ++cntt << ":" << endl;
        scanf("%lld%lld", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &tmp);
            insert_string(tmp);
        }

        for(int i = 1; i <= m; i++){
            scanf("%lld", &tmp);
            printf("%lld\n", find_string(tmp));
        }
    }
    return 0;
}