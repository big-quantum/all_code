#include<bits/stdc++.h>
using namespace std;
const int MAXN = 800005;
// int n, cnt;
// map<string, vector<int>> diction;
string s[200005];

int head[MAXN], _next[MAXN], to[MAXN], cnt, tim[MAXN], n;

void add(int u, int v, int w){
    to[++cnt] = v;
    tim[cnt] = w;
    _next[cnt] = head[u];
    head[u] = cnt;
}

string substr_end(string s, int n){
    string a = "";
    for(int j = s.size() - n; j <= s.size(); j++){
        a += s[j];
    }
    return a;
}

// int flag;//2:doctor_win,1:amiya_win,-1:draw
// void play(string amiya){
//     if(flag != 0) return;
//     if(diction[substr_end(amiya, 3)].empty()){
//         flag = 1;
//         return;
//     } else {
//         for(auto doctor_pos : diction[substr_end(amiya, 3)]){
//             if(diction.find(substr_end(s[doctor_pos], 3)) == diction.end()){
//                 flag = 2;
//                 return;
//             } else {
//                 for(auto amiya_new_pos : diction[substr_end(s[doctor_pos], 3)]){
//                     if(amiya_new_pos == doctor_pos){
//                         flag = -1;
//                         return;
//                     }
//                     play(s[amiya_new_pos]);
//                 }
//             }        
//         }
//     }
// }
map<string, int> diction;
int cntt;

int dist[400005];
bool in_queue[200005];

long long spfa(int from){
    int cnt = 1;
    memset(dist, 0, sizeof(dist));
    dist[from] = 0;
    queue<int> q;
    q.push(from);
    memset(in_queue, false, sizeof(in_queue));
    in_queue[from] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        in_queue[p] = false;
        for(int i = head[p]; i != 0; i = _next[i]){
            int t = to[i], w = tim[i];
            if(dist[t] < dist[p] + w){
                dist[t] = dist[p] + w;
                cnt++;
                if(!in_queue[t]){
                    in_queue[t] = true;
                    q.push(t);
                }
            }
        }
        if(cnt > n + 105){
            cnt = -1;
            break;
        }
    }
    return cnt;
}

int main(){
    freopen("play.in", "r", stdin);
    freopen("play.out", "w", stdout);
    cin >> n;
    if(n == 1){
        string a;
        cin >> a;
        if(a.substr(0,3) == substr_end(a, 3)) cout << "Draw" << endl;
        else cout << "Amiya" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        //cout << s[i].substr(0,3) << endl;
        if(!diction[s[i].substr(0, 3)]) diction[s[i].substr(0, 3)] = ++cntt;
        if(!diction[substr_end(s[i], 3)]) diction[s[i].substr(0, 3)] = ++cntt;
        add(diction[s[i].substr(0, 3)], diction[substr_end(s[i], 3)], 1);
    }
    for(int i = 1; i <= n; i++){
        int ans = spfa(diction[substr_end(s[i], 3)]);
        if(ans == -1)cout << "Draw" << endl;
        if(ans % 2 == 0) cout << "Doctor" << endl;
        else cout << "Amiya" << endl;
    }
    return 0;
}
/*
abcd
bcdab
bcdbc
bcdcd
bcdda
*/