#include<bits/stdc++.h>
using namespace std;
int n,opt[105][105],ans;

int main(){
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	cin >> n;
	opt[0][0] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			opt[i][j] = opt[i - 1][j - 1] + opt[i - j][j];
	for(int i = 1;i <= n;i++)
		ans += opt[n][i];
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
