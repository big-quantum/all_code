#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int tmp;
            cin >> tmp;
            if((i + 1) % 3 == 0 && (j + 1) % 3 == 0) ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}