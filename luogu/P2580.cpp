#include<bits/stdc++.h>
using namespace std;

int _next[500005][27], cnt = 1, exvis[500005], vis[500005];
int n, m;

void insert_string(string s){
    int cur = 1;
    for(auto a : s){
        if(!_next[cur][a - 'a'])
            _next[cur][a - 'a'] = ++cnt;
        cur = _next[cur][a - 'a'];
        
    }
    exvis[cur] = 1;
}

int find_string(string s){
    int cur = 1;
    for(auto a : s){
        if(!_next[cur][a - 'a']) return 0;
        cur = _next[cur][a - 'a'];
    }
    if(vis[cur]){
        return 2;
    }
    if(exvis[cur]){
        vis[cur] = 1;
        return 1;
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert_string(s);
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        switch (find_string(s)) {
            case 0:
                cout << "WRONG" << endl;
                break;
            case 1:
                cout << "OK" << endl;
                break;
            case 2:
                cout << "REPEAT" << endl;
                break;
            default:
                cout << "WRONG" << endl;
                break;
        }    
    }


    return 0;
}