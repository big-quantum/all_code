#include<bits/stdc++.h>
using namespace std;

int n, k;
string mode = "respect";

bool find(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'r'){
            bool flag = true;
            for(int j = i; j < mode.size(); j++){
                if(s[j] != mode[j - i]) flag = false;
            }
            if(flag) return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        int cnt = 0;
        cin >> s;
        cin >> k;
        if(k == 0) {
            if(find(s)) cnt++;
        } else {
            int from, to;
            cin >> from;
            string tmp = "";
            for(int j = 0; j < from; j++){
                tmp += s[j];
            }
            if(find(tmp)) cnt++;
            for(int j = 2; j <= k; j++){
                tmp = "";
                cin >> to;
                for(int z = from; z < to; z++){
                    tmp += s[z];
                }
                if(find(tmp)) cnt++;
                from = to;
            }
            tmp = "";
            for(int j = from; j < s.size(); j++){
                tmp += s[j];
            }
            if(find(tmp)) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}