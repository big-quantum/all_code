#include<bits/stdc++.h>
using namespace std;

int n, m, q;
struct node {
    vector<int> to;
    int out;
    int in;
};

node gra[500005];

void check(){

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int fr, too;
        cin >> fr >> too;
        gra[fr].to.push_back(too);
        gra[fr].out++;
        gra[too].in++;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int t, u, v;
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            gra[u].out--;
            gra[v].in--;
            check();
        }        
    }
    



    return 0;
}