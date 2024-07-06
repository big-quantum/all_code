#include<bits/stdc++.h>
using namespace std;
int n,f,i,l,m,r,a[100];
int main(){
	cin>>n>>f;
	for(i=1;i<=n;i++)
	cin>>a[i];
	l=1;
	r=n;
	do
	{
		m=(l+r)/2;
		if(f<=a[m]){
			r=m;
		}
		else 
		l=m+1;
	}while(l<r);
	cout<<l<<endl;
	return 0;
} 
