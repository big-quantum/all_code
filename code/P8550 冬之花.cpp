#include<bits/stdc++.h>
using namespace std;
int n,a[10],x,t;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>x;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		if(n==1){
			if(((x>0&&a[1]<0)||(x<0&&a[1]>0)&&x%a[1]==0)||x==0) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		} else {
			bool flag=true;
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]!=a[j]) flag=false;
				}
			}
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}	
	return 0;
} 
