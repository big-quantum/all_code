#include<bits/stdc++.h>
using namespace std;
string m[102];
char xu[102],x[102];
int q[102],b[102],l[102],n,j[102],y,w,c,xi,ba,ans,boss=-1,s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m[i]>>q[i]>>b[i]>>xu[i]>>x[i]>>l[i];
	for(int i=1;i<=n;i++) {
		if(q[i]>80&&l[i]>=1)
			j[i]=j[i]+8000;
		if(q[i]>85&&b[i]>80)
			j[i]=j[i]+4000;
		if(q[i]>90)
			j[i]=j[i]+2000;
		if(q[i]>85&&x[i]=='Y')
			j[i]=j[i]+1000;
		if(b[i]>80&&xu[i]=='Y')
			j[i]=j[i]+850;
		if(j[i]>boss){
			boss=j[i];
			s=i;
		}
		ans=ans+j[i];
	}
	cout<<m[s]<<endl;
	cout<<j[s]<<endl;
	cout<<ans<<endl;
	return 0;
} 
