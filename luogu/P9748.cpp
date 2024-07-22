#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans;
int main(){
    cin >> n;
    while (n != 0){
        cnt++;
        if(n % 3 == 1 && !ans){
            ans = cnt;
        }
        n -= ceil(n / 3.0);
    }
    cout << cnt << " " << ans << endl;
    return 0;
}