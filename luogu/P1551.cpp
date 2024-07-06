#include<bits/stdc++.h>
using namespace std;

int n, m, p;
int fa[5005];

void create_fa(int n){
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int find_fa(int x){
    if(fa[x] == x) return x;
    else{
        fa[x] = find_fa(fa[x]);
        return fa[x];
    }
}

void together_fa(int a, int b){
    fa[find_fa(a)] = find_fa(b);
}

int main(){
	cin >> n >> m >> p;
    create_fa(n);
    for (int i = 1; i <= m; i++) {
        int m1, m2;
        cin >> m1 >> m2;
        together_fa(m1, m2);
    }
    
    for (int i = 1; i <= p; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        if(find_fa(p1) == find_fa(p2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

	return 0;
}