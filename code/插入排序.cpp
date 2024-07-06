#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[1005],x;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(i=2;i<=n;i++){
		x=a[i];
		for(j=i-1;j>=0;j--)
			if(a[j]>x) a[j+1]=a[j]; 
			else break;
		if(x!=a[i])	a[j+1]=x;
	} 
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
