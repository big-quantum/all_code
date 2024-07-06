#include <bits/stdc++.h>
using namespace std;

struct node{
    int need, dui, num;
    map<string,pair<int, int>> number;//frist = need, second = dui;
    string key[105];
};

struct space{
    int from, need;
    bool to;
    map<string,pair<int, int>> number;//first = from, second = need;
};

int n, op, tmp = 0;

map<string, node> struct_name;
map<string, space> stru_sp;
map<long long, string> stru_addr;

void start(){
    struct_name["byte"].need = 1;
    struct_name["byte"].dui = 1;
    struct_name["short"].need = 2;
    struct_name["short"].dui = 2;
    struct_name["int"].need = 4;
    struct_name["int"].dui = 4;
    struct_name["long"].need = 8;
    struct_name["long"].dui = 8;
}

void op1(){
    int k;
    string s_name;
    cin >> s_name >> k;
    int sub = 0;
    struct_name[s_name].num = k;
    for(int j = 0; j < k; j++){
        string t, name;
        cin >> t >> name;
        sub = max(sub, struct_name[t].dui);
        struct_name[s_name].number[name].first = struct_name[t].need;
        struct_name[s_name].number[name].second = struct_name[t].dui;
        struct_name[s_name].key[j] = name;
    }
    struct_name[s_name].need = sub * k;
    struct_name[s_name].dui = sub;
    cout << struct_name[s_name].need << " " << struct_name[s_name].dui << endl; // answer
}

void op2(){
    string t, name;
    cin >> t >> name;
    stru_sp[name].from = tmp;
    for(int i = 1; i <= stru_sp[name].need; i++){
        stru_addr[tmp + i - 1] = name;
    }
    cout << tmp << endl; // answer
    stru_sp[name].need = struct_name[t].need;
    tmp = tmp + stru_sp[t].need;
    if(!struct_name[t].number.empty()){
        stru_sp[name].to = true;
        for(int i = 0; i < struct_name[t].num; i++){
            stru_sp[name].number[struct_name[t].key[i]].first = tmp + stru_sp[name].need * i;
            stru_sp[name].number[struct_name[t].key[i]].second = struct_name[t].number[struct_name[t].key[i]].first;
        }
    }
}

void op3(){
    string s;
    cin >> s;
    int len = s.size(), ans = 0;
    for(int i = 0; i < len; i++){
        string tmp[105];
        int cnt = 1;
        if(s[i] != '.') tmp[cnt] += s[i];
        else {
            cnt++;
            tmp[cnt] = "";
        }
        if(cnt == 1) cout << stru_sp[tmp[cnt]].from << endl;
        else for(int i = 1; i <= cnt; i++){
            ans = stru_sp[tmp[i]].number[tmp[i + 1]].first;
        }
        
    }
    cout << ans << endl;
}

void op4(){
    int addr;
    cin >> addr;
    cout << stru_addr[addr] << endl;
}

int main() {
    start();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> op;
        if(op == 1){
            op1();
        }
        if(op == 2){
            op2();
        }
        if(op == 3){
            op3();
        }
        if(op == 4){
            op4();
        }
    }
    return 0;
}