#include<bits/stdc++.h>
using namespace std;

int tree[10005], n, m;

int lowbit(int x){
    return x&(-x);
}

void update(int i, int j){
    for(int pos = i; pos <= n; pos += lowbit(pos)){
        tree[pos] += j;
    }
}

int query(int i){
    int ans = 0;
    for(int pos = i; pos > 0; pos -= lowbit(pos)){
        ans += tree[pos];
    }
    return ans;
}

int query(int i, int j){
    return query(j) - query(i - 1);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        update(i, tmp);
    }

    for(int i = 1; i <= m; i++){
        int tmp, x, y;
        cin >> tmp >> x >> y;
        if(tmp == 1){
            update(x, y);
        } else {
            cout << query(x, y) << endl;
        }
    }

    return 0;
}