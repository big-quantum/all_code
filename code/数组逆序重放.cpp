#include<bits/stdc++.h>
using namespace std;
int n,num[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	reverse(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<' ';
	return 0;
} 
