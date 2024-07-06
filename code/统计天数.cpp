#include<bits/stdc++.h>
using namespace std;
int n,q[2000000],c=-1,ans=-1,qu;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>q[i];
	for(int i=1;i<=n;i++){
		if(q[i]>c) {
			c=q[i];
			qu++;
		}
		else {
			if(qu>ans)
				ans=qu;
				qu=0;
				c=-1;
			if(q[i]>c)
				c=q[i];
				qu++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
