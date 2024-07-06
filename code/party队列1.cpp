#include<bits/stdc++.h>
using namespace std;
int m,n,k,l[2005],g[2005],lr,gr;
int main(){
	//freopen("party.in","r",stdin)
	//freopen("party.out","w",stdout)
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
		l[i] = i;
	lr = m+1;
	for(int i=1;i<=n;i++)
		g[i] = i;
	gr = n+1;
	for(int i=1;i<=k;i++){
		cout<<l[i]<<" "<<g[i]<<endl;
		l[lr] =l[i];
		lr++;
		g[gr] =g[i];
		gr++;
	}
	return 0;
} 
