#include<bits/stdc++.h>
using namespace std;

deque<int> q;
int n, t, a[50005], ans;

bool check(int num){
    int dp[50005], cnt = INT_MAX;
    memset(dp, 0, sizeof(dp));
    while(!q.empty()) q.pop_back();
    q.push_back(0);
    for(int i = 1; i <= n; i++){
        while(!q.empty() && i - q.front() > num + 1) q.pop_front();
        if(!q.empty()) dp[i] = dp[q.front()] + a[i];
        while(!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
        q.push_back(i);
    }
    for(int i = n - num; i <= n; i++){
        cnt = min(cnt, dp[i]);
    }
    return cnt > t;
}

int main(){
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 0, r = n + 1, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
        } else {
            r = mid + 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    return 0;
}