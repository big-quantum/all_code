#include<bits/stdc++.h>
using namespace std;

int n, m, fa[10004], _rank[10005];

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        _rank[i] = 1;
    }
}

int find(int x){
    if(fa[x] == x) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int x, int y){
    int a = find(x), b = find(y);
    if(_rank[a] >= _rank[b]){
        fa[b] = a;
    } else {
        fa[a] = b;
    }
}


int main(){
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1){
            merge(x, y);
        } else {
            if(find(x) == find(y)) cout << "Y" << endl;
            else cout << "N" << endl; 
        }
    }

    
    return 0;
}