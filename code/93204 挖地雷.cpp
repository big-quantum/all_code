#include<bits/stdc++.h>
using namespace std;
int n,w[205],f[10005],cnt=1;
struct node{
	int x,y;
}con[10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	cin>>con[cnt].x>>con[cnt].y;
	while(con[cnt].x!=0||con[cnt].y!=0){
		cnt++;
		cin>>con[cnt].x>>con[cnt].y;
	}
	cout<<cnt;
	return 0;
} 
