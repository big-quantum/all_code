#include<bits/stdc++.h>
using namespace std;

int n, maxn = -1, minn = INT_MAX, num[100005], k, ans = -1, maxpos;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        if(maxn < num[i]){
            maxpos = i;
            maxn = num[i];
        }
        minn = min(minn, num[i]);
    }
    for(int i = 1; i <= n; i++){
        if(maxn - num[i] < k && i != maxpos) ans = max(ans, min(maxn, num[i]));
    }
    if(maxn - minn > k) ans = max(maxn, ans);
    else ans = max(minn, ans);
    cout << ans << endl;
    return 0;
}