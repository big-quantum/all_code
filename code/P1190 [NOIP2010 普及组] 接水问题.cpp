#include<bits/stdc++.h>
using namespace std;
int n,m,w,s[105],minn=INT_MAX,mini;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w;
		for(int i=1;i<=m;i++){
			if(s[i]<minn){
				minn=s[i];
				mini=i;
			}
		}
		s[mini]+=w; 
		minn=INT_MAX;
	}
	int maxx=INT_MIN;
	for(int i=1;i<=m;i++){
		if(s[i]>maxx){
			maxx=s[i];
		}
	}
	cout<<maxx<<endl;
	return 0;
} 
