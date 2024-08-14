#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> s;
    int len = s.size();
    for (int i = 1; i < len; i++){
        if(s[i - 1] != s[i]) cnt++;
    }
    //if(cnt == len - 1) cout << len << endl;
    if(cnt == 0){
        if(len <= 4){
            cout << len << endl;
        } else if(len < 10){
            cout << 4 << endl;  
        } else if(len < 100) {
            cout << 5 << endl;
        } else {
            cout << 6 << endl;
        }
    }
    cout << len << endl;
    return 0;
}