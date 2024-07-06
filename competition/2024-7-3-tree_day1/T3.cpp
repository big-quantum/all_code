#include<bits/stdc++.h>//seg?
using namespace std;
const int MAXN1 = 200005;
const int MAXN2 = 1000005;

int n, q;
vector<int> tree[MAXN1], son[MAXN2];
int fa[MAXN2], tree_ans[MAXN1];
bool light[MAXN2], lazy[MAXN1];

map<int, vector<int>> lazy_u;
bool check(int p, int cnt){
    if(lazy[fa[p]] || check(fa[p], cnt+1)){
        lazy_u[p].push_back(cnt);
    }
    if (lazy_u[p].empty()) return false;
    else return true;
}

void build_tree(int fa){
    if(light[fa]) tree_ans[fa]++;
    for(auto i : son[fa]){
        tree[fa].push_back(i);
        build_tree(i);
    }
    for(auto i : tree[fa]){
        tree_ans[fa] += tree_ans[i];
    }
    
}

int main(){
    freopen("T3.in", "r", stdin);
    freopen("T3.out", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> fa[i + 1];
        son[fa[i + 1]].push_back(i + 1);//递归
        //tree[fa[i + 1]].push_back(i + 1);
    }
    for(int i = 1; i <=n; i++){
        cin >> light[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        string s;
        int p;
        cin >> s >> p;
        if(s == "get"){
            if(check(p, 1)){
                for(auto i : lazy_u[p]){

                }
            }
        } else {
            lazy[p] = !lazy[p];
        }
    }
    return 0;
}
