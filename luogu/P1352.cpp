#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int n;
bool iffa[MAXN];
struct node{
    int val;
    vector<node*> son;
}point[MAXN];
unordered_map<node*, int> l, r;

void dfs(node* a){
    if(a->son.size() == 0){
        l[a] = a->val;
        r[a] = 0;
        return;
    }
    for(int i = 0; i < a->son.size(); i++){
        node* child = a->son[i];
        dfs(child);
        l[a] += r[child];
        r[a] += max(l[child], r[child]);
    }
    l[a] += a->val;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        point[i].val = val;
    }
    for(int i = 1; i < n; i++){
        int l, k;
        cin >> l >> k;
        point[k].son.push_back(&point[l]);
        iffa[l] = true;
    }
    node* root;
    for(int i = 1; i <= n; i++){
        if(!iffa[i]){
            root = &point[i];
            break;
        }
    }
    dfs(root);
    cout << max(l[root], r[root]) << endl;
    return 0;
}