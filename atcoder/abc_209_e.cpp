#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int n, in[MAXN], win[MAXN];
vector<int> gra[MAXN];
int get(string s){
    int ans = 0;
    if(s[0] >= 'a') ans += s[0] - 'a' + 26;
    else ans += s[0] - 'A';
    ans *= 52; 
    if(s[1] >= 'a') ans += s[1] - 'a' + 26;
    else ans += s[1] - 'A';
    ans *= 52; 
    if(s[2] >= 'a') ans += s[2] - 'a' + 26;
    else ans += s[2] - 'A';
    return ans;
}

string s[MAXN];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        gra[get(s[i].substr(s[i].size() - 3, 3))].push_back(get(s[i].substr(0, 3)));
        in[get(s[i].substr(0, 3))]++;
    }
    queue<int> q;
    for(int i = 0; i <= get("zzz"); i++){
        if(in[i] == 0){
            q.push(i);
            win[i] = 1;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : gra[u]){
            in[v]--;
            if(win[u] == 1 && win[v] == 0){
                win[v] = -1;
                q.push(v);
            } else if(in[v] == 0 && win[v] == 0){
                win[v] = 1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(win[get(s[i].substr(s[i].size() - 3, 3))] == 1) cout << "Takahashi" << endl;
        else if(win[get(s[i].substr(s[i].size() - 3, 3))] == -1) cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }
    return 0;
}