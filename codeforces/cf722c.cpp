#include<bits/stdc++.h>
using namespace std;

int n, a[100005], s[100005], fa[100005];
long long sum[100005], ans, anss[100005];

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    int i = find(fa[x]), j = find(fa[y]);
    //if(i == j) return;
    fa[j] = i;
    sum[i] += sum[j];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(int i = n; i >= 1; i--){
        fa[s[i]] = s[i];
        sum[s[i]] = a[s[i]];
        if(fa[s[i] - 1]) merge(s[i] - 1, s[i]);
        if(fa[s[i] + 1]) merge(s[i] + 1, s[i]);
        ans = max(ans, sum[find(s[i])]);
        anss[i] = ans;
    }
    for(int i = 2; i <= n; i++){
        cout << anss[i] << endl;
    }
    cout << 0;
    return 0;
}