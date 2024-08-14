#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000005;

int n, ans[MAXN], mix[MAXN], tot[MAXN], cnt;
vector<pair<int, int> > up, down;
string s;

bool cmp1(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    cin >> n;
    memset(mix, 1, sizeof(mix));
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '(') tot[i]++;
            if(s[j] == ')') tot[i]--;
            mix[i] = min(mix[i], tot[i]);
        }
        if(tot[i] >= 0){
            up.push_back(make_pair(mix[i], i));
        } else {
            down.push_back(make_pair(mix[i] - tot[i], i));
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
            if(all + mix[i.second] < 0){
                cout << "impossible" << endl;
                return 0;
            }
			all += tot[i.second];
        }
        for(auto i : down){
            if(all + mix[i.second] < 0){
                cout << "impossible" << endl;
                return 0;
            }
			all += tot[i.second];
        }
        for(auto i : up){
            cout << i.second << endl;
        }
        for(auto i : down){
            cout << i.second << endl;
        }
    }
    return 0;
}
