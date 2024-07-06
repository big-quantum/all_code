#include<bits/stdc++.h>
using namespace std;
int n,m,k[5005],s[5005],a,minn,all;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>s[i];
	} 
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(s[j]<s[j+1]||(s[j]==s[j+1]&&k[j]>k[j+1])){
				swap(s[j],s[j+1]);
				swap(k[j],k[j+1]);
			}
		}
	}
	a=floor(m*1.5);
	minn=s[a];
	for(int i=1;i<=n;i++){
		if(s[i]>=minn){
			all++;
		}
	}
	cout<<minn<<" "<<all<<endl;
	for(int i=1;i<=all;i++){
		cout<<k[i]<<" "<<s[i]<<endl;
	} 
	return 0;
}
