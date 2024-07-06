#include<bits/stdc++.h>
using namespace std;
int m,n,k,l=1,g=1;
int main(){
	cin>>m>>n>>k;
	for(int i=1;i<=k;i++){
		cout<<g<<" "<<l<<endl;
		g++;
		if(g==m+1)
			g = 1;
		l++;
		if(l==n+1)
			l = 1;
	}
	return 0;
} 
