#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m[200005];
void dfs(int i,int s) {
	m[i]+=s;
	if(i>1) dfs(a[i],s+1);
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n;
	m[1]=1;
	for(int i=2; i<=n; i++) cin>>a[i];
	for(int i=2; i<=n; i++) dfs(i,1);
	for(int i=1; i<=n; i++) cout<<m[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
