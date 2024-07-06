#include<bits/stdc++.h>
using namespace std;

int n,m;
int num[20];
int dp[20][20];

int dfs(int lenth, int f, bool flag){
    if(lenth == 0) {
        return 1;
    }
    if(flag == 0 && dp)
}

int solve(int x) {
    int len = 1;
    while(x != 0) {
        num[len++] = x % 10;
        x = x / 10;
    }
    dfs(len, )
}
int main() {
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        } else {
            cout << solve(m) - solve(n - 1) << endl;
        }
    }
    
    return 0;
}