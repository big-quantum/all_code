#include<bits/stdc++.h>
using namespace std;

int n, q[1000005], ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> q[i];
    }
    sort(q + 1, q + n + 1);
    for(int i = n; i >= n - 32 && i >= 1; i--){
        for(int j = i - 1; j >= n - 32 && j >= 1; j--){
            ans = max(ans, q[i] & q[j]);
        }
    }
    cout << ans << endl;
    return 0;
}