#include<bits/stdc++.h>
using namespace std;

int n, m, a[100005];

bool check(int x){
    int tmp = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(cnt + a[i] <= x){
            cnt = cnt + a[i];
        } else {
            tmp++;
            cnt = a[i];
            if(cnt > x) return false;
        }
    } 
    if(cnt) tmp++;
    return tmp <= m;
}

int rf(int l, int r){
    int mid, ans;
    while(l <= r){
        //cout << l << " " << r << endl;
        mid = (l + r) >> 1;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}

int main(){
    cin >> n >> m;
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    cout << rf(l, r) << endl;

    return 0;
}