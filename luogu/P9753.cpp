#include<bits/stdc++.h>
using namespace std;

int n;
int _next[2000005][30];
int dp[2000005];
string s;

int main(){
    cin >> n;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++){
        s[i] = s[i] - 'a';
    }

    for(int i = n - 1; i >= 1; i--){
        if(s[i] == s[i + 1]){
            for(int j = 0; j < 26; j++){
                _next[i][j] = _next[i + 2][j];
            }
            if(i + 2 <= n){
                _next[i][s[i + 2]] = i + 2;
            }
            dp[i] = dp[i + 2] + 1;
        } else if(_next[i + 1][s[i]]){
            int pos = _next[i + 1][s[i]];
            for(int j = 0; j < 26; j++){
                _next[i][j] = _next[pos + 1][j];
            }
            if(pos + 1 <= n){
                _next[i][s[pos + 1]] = pos + 1;
            }
            dp[i] = dp[pos + 1] + 1;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}