#include<bits/stdc++.h>
using namespace std;

int n, k;


int main(){
    vector<vector<int>> mapp(30, vector<int>(1));
    cin >> n >> k;
    string mode;
    cin >> mode;
    for(int i = 0; i < k; i++){
        mapp[mode[i] - 'a'][0]++;
        mapp[mode[i] - 'a'][mapp[mode[i] - 'a'][0]] = i;
    }
    for(int i = 1; i <= n; i++){
        int ans = 0;
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            int tmp = s[j] - 'a', cnt = INT_MAX;
            if(mapp[tmp][0]){
                for(int k = 1; k <= mapp[tmp][0]; k++){
                    cnt = min(cnt, abs(j - mapp[tmp][k]));
                }
            } else cnt = k;
            ans += cnt;
        }
        cout << ans << endl;
    }

    return 0;
}