#include<bits/stdc++.h>
using namespace std;

char ans[3005], s[3005], t[3005];
int dp[3005][3005], flag[3005][3005], cnt;

void back(int x, int y){
	if(x == 0 || y == 0) return;
	if(flag[x][y] == 1) ans[cnt++] = s[x], back(x - 1, y - 1);
	if(flag[x][y] == 2) back(x - 1, y);
	if(flag[x][y] == 3) back(x, y - 1);
	return;
}

int main(){
	cin >> (s + 1) >> (t + 1);
	int lens = strlen(s + 1), lent = strlen(t + 1);
	for(int i = 1; i <= lens; i++){
		for(int j = 1; j <= lent; j++){
			if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1, flag[i][j] = 1;
			else if(dp[i - 1][j] > dp[i][j - 1]) dp[i][j] = dp[i - 1][j], flag[i][j] = 2;
			else dp[i][j] = dp[i][j - 1], flag[i][j] = 3;
		}
	}
	back(lens, lent);
	reverse(ans, ans + cnt);
	cout << ans << endl;
	
	
	return 0;
}
