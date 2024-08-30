#include<bits/stdc++.h>
using namespace std;

int n, q, a[100005], st[100005][20];
map<int, long long> ans;

int gcd(int a, int b){
    if(b != 0) return gcd(b, a % b);
    else return a;
}

int get_gcd(int l, int r){
    int k = log2(r - l + 1);
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int rf(int k, int l, int r, int c){
    if(l == r) return l;
    if(l + 1 == r) 
        if(get_gcd(k, r) == c) return r;
        else return l;
    int mid = (l + r) >> 1;
    if(get_gcd(k, mid) == c) return rf(k, mid, r, c);
    else return rf(k, l, mid - 1, c);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> st[i][0];
    }
    for(int j = 1; j <= 19; j++){
        for(int i = 1; i <= n - (1 << j) + 1; i++){
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1; i <= n; i++){
        int l = i;
        while(l <= n){
            int num = get_gcd(i, l);
            int r = rf(i, l, n, num);
            ans[num] += r - l + 1;
            l = r + 1;
        }
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int tmp;
        cin >> tmp;
        cout << ans[tmp] << endl;
    }

    return 0;
}