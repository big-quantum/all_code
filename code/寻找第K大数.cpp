#include<bits/stdc++.h>
using namespace std;
int n,k,m[10005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>m[i];
	sort(m+1,m+1+n);
	cout<<m[n-k+1]<<endl;
	return 0;
}
