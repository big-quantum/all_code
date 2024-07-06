#include<bits/stdc++.h>
using namespace std;
int p[30005],n,w,lft,rgt,ans;
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&w,&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&p[i]);
	sort(p + 1,p + 1 + n);
	lft = 1;
	rgt = n;
	while(lft <= rgt){
		if (p[lft] + p[rgt] <= w) lft++;	
		rgt--;
		ans++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
