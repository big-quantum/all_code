#include<bits/stdc++.h>
using namespace std;

int n, k, num[505], ans, pos[505];
vector<pair<int, int>> anss;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        pos[num[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        vector<int> swapp;
        for(int j = 1; j < i; j++){
            if(pos[j] - pos[i] >= k) {
                swapp.push_back(j);
            }
        }
        for(int j = swapp.size() - 1; j >= 0; j--){
            ans++;
            swap(pos[i], pos[swapp[j]]);
            anss.push_back(make_pair(pos[swapp[j]], pos[i]));
            i = swapp[j];
        }
    }
    cout << ans << endl;
    for(auto i : anss){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}