#include<bits/stdc++.h>
using namespace std;
int n,t[10005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(t[i]>t[j]){
				int amp=t[i];
				t[i]=t[j];
				t[j]=amp;
			}
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
}
