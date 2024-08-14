#include<bits/stdc++.h>
using namespace std;

int n, group[205][205];
int fa[205], cnt;
vector<int> d;

void _init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x){
    if(fa[x] == x){
        return x;
    } else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int a, int b){
    fa[find(b)] = find(fa[a]);
}

int main(){
	//freopen("group.in", "r", stdin);
	//freopen("group.in", "w", stdout);
	cin >> n;
    _init();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> group[i][j];
            if(group[i][j]) merge(i, j);
        }
    }
	
    for(int i = 1; i <= n; i++){
        if(fa[i] == i) cnt++;
    }
	
    cout << cnt << endl;
	return 0;
}
