#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3000005;

int cnt = 1, tt, cntt[MAXN], _next[MAXN][100];

void insert(string s){
    int cur = 1;
    for(auto c : s){
        if(!_next[cur][c - '0']){
            _next[cur][c - '0']= ++cnt;
        }
        cur = _next[cur][c - '0'];
        cntt[cur]++;
    }
}

int find(string s){
    int cur = 1;
    for(auto c : s){
        if(!_next[cur][c - '0']) return 0;
        cur = _next[cur][c - '0'];
    }
    return cntt[cur];
}

int main(){
    scanf("%d", &tt);
    while(tt--){
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 0; i <= cnt; i++)
            for(int j = 0; j < 100; j++)
                _next[i][j] = 0;
        for(int i = 0; i <= cnt; i++)
            cntt[i] = 0;
        cnt = 1
        string a;
        for(int i = 1; i <= n; i++){
            cin >> a;
            insert(a);
        }
        for(int i = 1; i <= q; i++){
            cin >> a;
            cout << find(a) << endl;
        }
    }
    return 0;
}
