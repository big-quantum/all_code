#include<bits/stdc++.h>
using namespace std;

int n, d, a, ans;

int main(){
    cin >> n;
    cin >> a;
    ans += a;
    for(int i = 2; i <= n; i++){        
        cin >> d;
        if(d > a) ans += d - a;
        a = d;
    }
    cout << ans << endl;
    return 0;
}