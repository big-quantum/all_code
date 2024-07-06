#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

string s, word[10005];
int cnt = 1, num, ans;
int n[50005];

void create(){
    n[1] = 1;
    for(int i = 2; i <= 50002; i++) {
        n[i] = n[i - 1] * i % mod;
    }
}

int main() {
    getline(cin, s);
    create();
    int len = s.size();
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') {
            cnt++;
            num = 0;
        }
        else {
            word[cnt][num++] = s[i];
        }
    }
    cnt++;

    for(int i = 1; i <= cnt; i++) {
        len = word[i].size();
        ans = (ans + n[len]) % mod;
    }
    cout << ans << endl;
    return 0;
}