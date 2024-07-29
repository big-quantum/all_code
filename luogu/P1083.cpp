#include<bits/stdc++.h>
using namespace std;

long long n, m, r[1000005], cf[1000005], d[1000005], s[1000005], t[1000005];

bool check(int k){
    memset(cf, 0, sizeof(cf));
    for(int i = 1; i <= k; i++){
        cf[s[i]] += d[i];
        cf[t[i] + 1] -= d[i];
    }
    long long tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp += cf[i];
        if(tmp > r[i]) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> d[i] >> s[i] >> t[i];
    }
    
    if(check(m)){
        cout << 0 << endl;
    } else {
        int l = 1, r = m, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(check(mid)){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << -1 << endl;
        cout << l << endl;
    }
    return 0;
}
/*// O(n + m)
int n, m, r[1000005];
int main(){
    cin >> n >> m;
    cin >> r[1];
    for(int i = 2; i <= n; i++){
        cin >> r[i];
        r[i] = r[i] - r[i - 1];
    }
    bool flag = false;
    for(int i = 1; i <= m; i++){
        int d, s, t;
        cin >> d >> s >> t;
        r[s] -= d;
        r[t] += d;
        for(int j = 1)
        if(r[s] < 0){
            cout << -1 << endl;
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << 0 << endl;
    return 0;
}
*/