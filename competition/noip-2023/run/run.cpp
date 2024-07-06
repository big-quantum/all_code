#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

long long n, m, c, t, k, d, ans;
int task[MAXN][3];
long long dp[MAXN][2];
bool flag[MAXN];
map<int, pair<bool, int>> cha;

int main() {
    freopen("run.in", "r", stdin);//remember to change
    freopen("run.out", "w", stdout);
    
    scanf("%lld%lld", &c, &t);
    while (t-- != 0) {
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &task[i][0], &task[i][1], &task[i][2]);
            cha[task[i][0]] = make_pair(true, i);
        }

        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if(cha[i].first == true && task[cha[i].second][1] <= k){
                dp[i][1] = max(dp[i - task[cha[i].second][1] + 1][0] + task[cha[i].second][2] - d * task[cha[i].second][1], dp[i - 1][0]);
            }
        }

        for(int i = 1; i <= n; i++ ){
            for (int j = 0; j <= 1; j++) {
                ans = max(dp[i][j], ans);
                dp[i][j] = 0;
            }
        }
        cout << ans << endl;
        cha.clear();
        ans = 0;
    }

    return 0;
}