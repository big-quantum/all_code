#include<bits/stdc++.h>
using namespace std;

string s, ans;
int num;

int main() {
    freopen("atoi.in", "r", stdin);
    freopen("atoi.out", "w", stdout);
    cin >> s;
    int length = s.size(), f = 1;
    bool flag = false;
    for (int i = 0; i < length; i++){
        if(s[i] == '-'){
            f = -1;
        }
        if(s[i] != ' '){
            ans+=s[i];
            while (s[i] >= '0' && s[i] <= '9') {
                i++;
                ans+=s[i];
            }
            break;
        } 
    }
    length = ans.size();
    for(int i = 0; i < length ; i++){
        if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        } 
    }
    num = num * f;

    cout << num << endl;
    return 0;
}