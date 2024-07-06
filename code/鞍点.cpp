#include<bits/stdc++.h>
using namespace std;
int a[10][10],minn=1000,maxx=-1,x,y;
int main(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(a[i][j]>maxx){
				maxx=a[i][j];
				x=j;
			}
		} 
		for(int j=1;j<=5;j++){
			if(a[j][i]<minn){
				minn=a[j][i];
				y=j; 
			}
		}
		if(maxx=minn){
			cout<<y<<" "<<x<<" "<<maxx;
			return 0;
		}
	} 
	cout<<"not found"<<endl;
} 
