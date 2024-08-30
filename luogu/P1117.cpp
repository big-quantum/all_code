#include<bits/stdc++.h>
using namespace std;

string s;
int f[200005], g[200005], ans;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        for(int i = 2; i < s.size() - 1; i++){
            for(int len = 1; len <= i / 2; len++){
                if(s.substr(i - len, len) == s.substr(i - len * 2, len)) f[i]++;
            }
            for(int len = 1; len <= (s.size() - i - 1) / 2; len++){
                if(s.substr(i + 1, len) == s.substr(i + len + 1, len)) g[i]++;
            }
            
            ans += g[i] * f[i];
        }for(int j = 1; j <= s.size(); j++){
                cout << f[j] << " ";
            }
            cout << endl;
            for(int j = 1; j <= s.size(); j++){
                cout << g[j] << " ";
            }
            cout << endl;
        cout << ans << endl;
    }
    


    return 0;
}
// 1
// aabbbb