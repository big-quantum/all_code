#include<bits/stdc++.h>
using namespace std;
int n,m,w,d,opt[12885];
int main() {
	freopen("charm.in","r",stdin);
	freopen("charm.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d",&w,&d);
		for(int j = m; j >= w; j--)
			opt[j] = max(opt[j],opt[j - w] + d);
	}
	printf("%d\n",opt[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
