#include<bits/stdc++.h>
using namespace std;
int T,M,w,v,opt[105][1005];
int main() {
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	cin >> T >> M;
	for(int i = 1;i <= M;i++){
		cin >> w >> v;
		for(int j = 1;j <= T;j++){
			opt[i][j] = opt[i - 1][j];
			if (j >= w)
				opt[i][j] = max(opt[i][j],opt[i - 1][j - w] + v);
		}	
	}
	cout << opt[M][T] << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
