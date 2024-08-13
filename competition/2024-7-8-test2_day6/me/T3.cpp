#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, h, x1[200005], x2[200005];
map<int, pair<bool, int>> street;
vector<int> push[200005];
bool vis[200005];
long long ans[200005];
//dfs
//将能互相影响的电线杆化为一个集合
//其中的一根电线杆向一边倒下，这一侧的电线杆会全部倒下
//
void pull(int t, bool flag){
    if(flag){
        int xx = x1[t];
        for(int i = xx; i >= xx - h; i--){
            if(street[i].first){
                vis[street[i].second] = true;
                push[t].push_back(street[i].second);
                pull(street[i].second, flag);
            }
        }
    } else {
        int xx = x1[t];
        for(int i = xx; i <= xx + h; i++){
            if(street[i].first){
                vis[street[i].second] = true;
                push[t].push_back(street[i].second);
                pull(street[i].second, flag);
            }
        }
    }
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(!vis[i]) return false;
    }
    return true;
}

void dfs(int t){
    pull(t, true);
    if(check()) ans[t] += 1;
    else dfs(t + 1);
    for(auto i : push[t]){
        vis[i] = false;
    }
    pull(t, false);
    if(check()) ans[t] += 1;
    else dfs(t + 1);
    for(auto i : push[t]){
        vis[i] = false;
    }
}


int main(){
    freopen("T3.in", "r", stdin);
    freopen("T3.out", "w", stdout);
    scanf("%d%d", &n, &h);
    for(int i = 1; i <= n; i++){
        scanf("&d", &x1[i]);
        x2[i] = x1[i];

        street[x1[i]] = make_pair(true, i);
    }
    //sort(x2, x2 + n + 1);
    // dfs(1);
    // for(int i = 1; i <= n; i++){
    //     if(ans[i] != 0){
    //         for(int j = i; j < n; j++){
    //             ans[i] = ans[i] * 2 % mod;
    //         }
    //         cout << ans[i] << " ";
    //     } else {
    //         cout << 0 << " ";
    //     }
    // }
    long long tmp = 1;
    for(int j = 1; j <= n; j++){
        tmp = tmp * 2 % mod;
    }
    cout << tmp << " ";
    return 0;
}
