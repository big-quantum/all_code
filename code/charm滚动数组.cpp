#include<bits/stdc++.h>
using namespace std;
int n,m,w,d,opt[2][12885];
int main(){
	freopen("charm.in","r",stdin);
	freopen("charm.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&w,&d);
		for(int j = 1;j <= m;j++){
			opt[i % 2][j] = opt[1 - i % 2][j];
			if (j >= w)
				opt[i % 2][j] = max(opt[i % 2][j],opt[1 - i % 2][j - w] + d); 
		}		
	}
	printf("%d\n",opt[n % 2][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
