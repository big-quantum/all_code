#include<bits/stdc++.h>
using namespace std;

long long n, m, k, s, t;
vector<pair<long long, long long>> tree[100005];
long long dist[100005], diss[100005];
long long dt[100005], ds[100005];
void dfst(int u, int f, int w){
    dist[u] = dist[f] + w;
    for(auto i : tree[u]){
        if(i.first != f){
            dfst(i.first, u, i.second);
        }
    }
}
void dfss(int u, int f, int w){
    diss[u] = diss[f] + w;
    for(auto i : tree[u]){
        if(i.first != f){
            dfss(i.first, u, i.second);
        }
    }
}

bool check(long long mid){
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += upper_bound(dt + 1, dt + 1 + n, mid - ds[i]) - dt - 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(auto j : tree[i]){
            if(ds[i] + dt[j.first] <= mid) cnt--;
        }
    }
    //cout << cnt << " " << mid << endl;
    return cnt > m;
}

int main(){
    cin >> n >> m >> k >> s >> t;
    for(int i = 1; i < n; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    dfst(t, 0, 0);
    dfss(s, 0, 0);
    for(int i = 1; i <= n; i++){
        dt[i] = dist[i];
        ds[i] = diss[i];
    }
    sort(dt + 1, dt + 1 + n);
    sort(ds + 1, ds + 1 + n);
    long long left = 0, right = 1e18, mid, ans = 1e18;
    while(left < right){
        mid = (right + left) / 2;
        if(check(mid)){
            right = mid;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << min(ans + k, min(diss[t], (long long)(1e9))) << endl;
    return 0;
}