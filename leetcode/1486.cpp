#include<bits/stdc++.h>
using namespace std;
int n, start, ans;
int main(){
    cin >> n >> start;
    ans = start;
    for(int i = 1; i < n; i++){
        ans = ans ^ (start + 2 * i);
    }
    cout << ans << endl;
    return 0;
}