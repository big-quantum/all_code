#include<bits/stdc++.h>
using namespace std;
int a, b, c, ans;
int main(){
    cin >> a >> b >> c;
    int ans = 0;
        for(int i = 31; i >= 0; i--){
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int c_bit = (c >> i) & 1;
            if(c_bit == 0){
                if(a_bit == 1) ans++;
                if(b_bit == 1) ans++;
            } else {
                if(a_bit == b_bit && a_bit == 0) ans++;
            }
        }
        cout << ans << endl;
    return 0;
}
// 1310 2429 2871
