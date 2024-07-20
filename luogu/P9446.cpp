#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, ans[MAXN], mix[MAXN], tot[MAXN], cnt;
vector<pair<int, int>> up, down;
string s[MAXN];

bool cmp1(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    cin >> n;
    memset(mix, 1, sizeof(mix));
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        for(int j = 0; j <= s[i].size(); j++){
            if(s[i][j] == '(') tot[i]++;
            if(s[i][j] == ')') tot[i]--;
            mix[i] = min(mix[i], tot[i]);
        }
        if(tot[i] >= 0){
            up.push_back(make_pair(mix[i], i));
        } else {
            down.push_back(make_pair(tot[i] - mix[i], i));
        }
        cnt += tot[i];
    }
    sort(up.begin(), up.end(), cmp1);
    sort(down.begin(), down.end(), cmp2);
    if(cnt != 0){
        cout << "impossible" << endl;
    } else {
        int all = 0;
        for(auto i : up){
            all += i.first;
            if(all < 0){
                cout << "impossible" << endl;
                return 0;
            }
        }
        for(auto i : down){
            all += i.first;
            if(all < 0){
                cout << "impossible" << endl;
                return 0;
            }
        }
        for(auto i : up){
            ans[i.second] = ++cnt;
        }
        for(auto i : down){
            ans[i.second] = ++cnt;
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}