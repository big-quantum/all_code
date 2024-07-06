#include<bits/stdc++.h>
using namespace std;

string s;
int len, ans;

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> len;
    cin >> s;

    for(int i = 0; i < len; i++){
        for(int j = 2; j <= len - i; j += 2){
            string tmp = s.substr(i, j);
            stack<char> str;
            int lenth = tmp.size();
            str.push(tmp[0]);
            for(int k = 1; k < lenth; k++){
                if(!str.empty() && str.top() == tmp[k]) str.pop();
                else str.push(tmp[k]);
            }
            if(str.empty()) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}