#include<bits/stdc++.h>//65
using namespace std;
//icpc湖北省赛h题
int n, m, k, num[15], maxnum = -1, cnt, ans;
pair<int, int> maxn, sub[15];
map<pair<int, int>, int> fish;
bool flag[15];
short mapp[1005][1005]; 
int dx[5] = {0, 0, 1, 0, -1}, dy[5] = {0, 1, 0, -1, 0};

int main(){
    freopen("heart.in", "r", stdin);
    freopen("heart.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> sub[i].first >> sub[i].second >> fish[sub[i]];
        for(int j = 0; j < 4; j++){
            int xx = sub[i].first + dx[j], yy = sub[i].second + dy[j];
            mapp[xx][yy] += fish[sub[i]];
            if(mapp[xx][yy] > maxnum){
                maxnum = mapp[xx][yy];
                maxn.first = xx, maxn.second = yy;
            }
        }
    }
    while(cnt != k){
        ans++;
        maxnum = -1;
        for(int i = 0; i < 5; i++){
            int xx = maxn.first + dx[i], yy = maxn.second + dy[i];
            pair<int, int> tmp = make_pair(xx, yy);
            for(int j = 1; j <= k; j++){
                if(sub[j] == tmp && xx > 0 && xx <= n && yy > 0 && yy <= m){
                    for(int k = 0; k < 5; k++){
                        int sx = xx + dx[k], sy = yy + dy[k];
                        mapp[sx][sy]--;
                    }
                    fish[tmp]--;
                }
            }
        }
        for(int i = 1; i <= k; i++){
            if(!fish[sub[i]] && !flag[i]){
                cnt++;
                flag[i] = true;
            } else {
                for(int j = 0; j < 5; j++){
                    int xx = sub[i].first + dx[j], yy = sub[i].second + dy[j];
                    if(mapp[xx][yy] > maxnum){
                        maxnum = mapp[xx][yy];
                        maxn.first = xx, maxn.second = yy;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
