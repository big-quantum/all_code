#include<bits/stdc++.h>//10
using namespace std;
const int mod = 998244353;
//百度之星省赛d题，码题集
long long n, k, len, ans;
string s;
map<pair<string, int>, int> memory;//

bool s_find(){
    for(int i = 0; i < n - 2; i++){
        if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0') { 
            
            return true;
        } else {
            continue;
        }
    }
    return false;
}

void dfs(int k, int pos){
    
    if(!s_find()) ans++, ans %= mod;
    if(k == 0) return;
    for(int i = 0; i < n && pos != i; i++){
        if(s[i] == '0'){
            s[i] = '1';
            dfs(k - 1, i);
            s[i] = '0';
        } else {
            s[i] = '0';
            dfs(k - 1, i);
            s[i] = '1';
        }
    } 
}

int main(){
    freopen("fuji.in", "r", stdin);
    freopen("fuji.out", "w", stdout);
    cin >> n >> k;
    cin >> s;
    dfs(k, -1);
    cout << ans % mod << endl;
    return 0;
}

/*
dp[i][j][0/1][0/1]表示前i位,有j次修改机会,a[i - 1] = 0/1,a[i] = 0/1; 


*/