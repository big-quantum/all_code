#include<bits/stdc++.h>
using namespace std;
int n, step1, ans;

int main(){
    cin >> n;
    if(n & 1 == 1) step1 = 0;
    for(int i = 1; n; n >>= 1, i++){
        if(n & 1 == 1){
            if(!step1) step1 = i;
            else{
                ans = max(ans, i - step1);
                step1 = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}