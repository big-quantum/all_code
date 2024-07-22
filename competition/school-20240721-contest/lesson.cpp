#include<bits/stdc++.h>
#include <cstring>
using namespace std;
int n, m, in[2005];
int head[10005], to[10005], _next[20005], cnt;
bool vis[10005];

void add(int u, int v){
    to[++cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt;
}

int que[205], f, tail;

void find(){
    for(int i = 1; i <= n; i++){
        if(in[i] == 0 && !vis[i]){
        	que[tail++] = i;
        	vis[i] = true;
		}
    }
}

bool tp(){
    find();
    while(f < tail){
        int p = que[f];
        f++;
        for(int i = head[p]; i != -1; i = _next[i]){
            in[to[i]]--;
        }
        find();
    }
    return tail == n;
}

int main(){
	//freopen("4.in", "r", stdin);
	//freopen("4.ans", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= 205; i++) head[i] = -1;
    for(int i = 1; i <= m; i++){
        int f, t;
        cin >> f >> t;
        add(t + 1, f + 1);
        in[f + 1]++;
    }
    if(tp() || m == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
