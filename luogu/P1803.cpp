#include<bits/stdc++.h>
using namespace std;

int n, pos, ans;
pair<int, int> com[1000005];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> com[i].first >> com[i].second;
    }
    sort(com + 1, com + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        if(pos <= com[i].first){
            pos = com[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}