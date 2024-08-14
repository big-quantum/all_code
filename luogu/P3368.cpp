#include<bits/stdc++.h>
using namespace std;

int n, m, tree[500005], num[500006];

int lowbit(int x){
    return x&-x;
}

void update(int x, int y, int k){
    for(int i = x; i <= n; i += lowbit(i)){
        tree[i] += k;
    }
    for(int i = y + 1; i <= n; i += lowbit(i)){
        tree[i] -= k;
    }
}

int query(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= lowbit(i)){
        ans += tree[i];
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= m; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            int a, b, t;
            cin >> a >> b >> t;
            update(a, b, t);
        } else {
            int t;
            cin >> t;
            cout << query(t) + num[t] << endl;
        }
    }
    return 0;
}