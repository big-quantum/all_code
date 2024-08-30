#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int f[MAXN][30][3], dp[MAXN][MAXN][MAXN];

int main(){
	memset(f, -1, sizeof(f));
	string s[3];
	for(int i = 0; i < 3; i++){
		cin >> s[i];
		s[i] = "1" + s[i];
		//f[0][s[i][0] - 'a'][i] = 0;
		for(int j = 1; j <= s[i].size(); j++){
			for(int k = 0; k < 26; k++){
				f[j + 1][k][i] = f[j][k][i];
			}
			f[j + 1][s[i][j] - 'a'][i] = j;
		}
	}
	int alen = s[0].size(), blen = s[1].size(), clen = s[2].size();
	for(int i = 1; i <= alen; i++){
		for(int j = 1; j <= blen; j++){
			for(int k = 1; k <= clen; k++){
				if(s[0][i] == s[1][j] && s[1][j] == s[2][k]){
					dp[i][j][k] = 2 * dp[i - 1][j - 1][k - 1] + 1;
					if(f[i][s[0][i] - 'a'][0] != -1 && f[j][s[1][j] - 'a'][1] != -1 && f[k][s[2][k]- 'a'][2] != -1){
						dp[i][j][k] -= dp[f[i][s[0][i]- 'a'][0] - 1][f[j][s[1][j] - 'a'][1] - 1][f[k][s[2][k] - 'a'][2] - 1] + 1;
					}
				} else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i - 1][j - 1][k] - dp[i][j - 1][k - 1] - dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	cout << dp[alen][blen][clen] << endl;
	return 0;
}
