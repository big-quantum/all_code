#include<bits/stdc++.h>
using namespace std;

string s, p;

bool findd(string ss, string pp){
    int sslength = ss.size(), pplength = pp.size();
    if(pp[0] >= 'a' && pp[0] <= 'z' && ss[0] == pp[0]) {
        if(findd(ss.substr(1, 2000), pp.substr(1, 2000))) return true;
    }
    if(pp[0] == '?'){
        if(findd(ss.substr(1, 2000), pp.substr(1, 2000))) return true;
    } 
    if(pp[0] == '*') {
        for(int i = 1; i <= sslength; i++){
            if(pp[1] >= 'a' && pp[1] <= 'z' && ss[i] == pp[1]) {
                if(findd(ss.substr(i, 2000), pp.substr(2, 2000))) return true;
            }
            if(pp[1] == '?'){
                if(findd(ss.substr(i, 2000), pp.substr(2, 2000))) return true;
            } else {
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    cin >> s;
    cin >> p;
    
    if(findd(s, p)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}