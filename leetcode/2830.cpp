#include<bits/stdc++.h>
using namespace std;
int n = 4;
vector<vector<int>> da = {{1,3,10},{1,3,3},{0,0,1},{0,0,7}};
    bool cmp(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int dp[100005];
        memset(dp, 0, sizeof(dp));
        map<int, vector<int>> end;
        for(int i = 0; i < offers.size(); i++){
            end[offers[i][1]].push_back(i);
        }
        sort(offers.begin(), offers.end(), cmp);
        for(int i = 0; i < offers.size(); i++){
            for(auto j : end[offers[i][1]]){
                dp[offers[i][1] + 1] = max(dp[offers[i][1]], dp[offers[j][0]] + offers[j][2]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
int main(){
    cout << maximizeTheProfit(n, da)<< endl;
}