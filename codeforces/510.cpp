#include<bits/stdc++.h>
using namespace std;

int n, in[105];
string s1, s2;
vector<int> gra[105];
bool vis[105];

int main(){
    cin >> n;
    cin >> s1;
    for(int i = 2; i <= n; i++){
        cin >> s2;
        bool flag = false;
        for(int i = 0; i < min(s1.size(), s2.size()); i++){
            if(s1[i] != s2[i]){
                gra[s1[i] - 'a'].push_back(s2[i] - 'a');
                in[s2[i] - 'a']++;
                flag = true;
                break;
            }
        }
        if(!flag && s1.size() > s2.size()){
            cout << "Impossible" << endl;
            return 0;
        }
        s1 = s2;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < 26; i++){
        if(!in[i]) q.push(i); 
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(vis[p]) continue;
        vis[p] = true;
        ans.push_back(p);
        for(auto to : gra[p]){
            in[to]--;
        }
        for(int i = 0; i < 26; i++){
            if(in[i] == 0 && !vis[i]) q.push(i); 
        }
    }
    for(int i = 0; i < 26; i++){
        if(in[i] > 0){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(auto i : ans) {
        cout << char('a' + i);
    }
    return 0;
}