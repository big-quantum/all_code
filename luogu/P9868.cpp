#include<bits/stdc++.h>
using namespace std;

int n, m;
char c[3005][2];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        c[i][0] = 'z';
        for(auto j : s){
            c[i][0] = min(c[i][0], j);
            c[i][1] = max(c[i][1], j);
        }
    }
    for(int i = 1; i <= n; i++){
        bool flag = false;
        for(int j = 1; j <= n; j++){
            if(c[i][0] >= c[j][1] && j != i){
                cout << 0;
                flag = true;
                break;
            }
        }
        if(!flag) cout << 1;
    }

    return 0;
}