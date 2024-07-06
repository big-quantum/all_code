#include<bits/stdc++.h>
using namespace std;
int bit[1005][1005][2],n,m,p,s[4];
string a,b;
bool flag;
void clean(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bit[i][j][0]=bit[i][j][1];
		}
	}
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&bit[i][j][0]); 
		}
	}
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	for(int i=1;i<=p;i++){
		if((a[i]=='A'&&a[i+1]=='B')||(a[i]=='B'&&a[i+1]=='A')||(a[i]=='C'&&a[i+1]=='C')||(a[i]=='D'&&a[i+1]=='D')){
			a[i]=' ';
			a[i+1]=' ';
			i++;
		}
		if((a[i]=='A'&&a[i+1]=='A'&&a[i+2]=='A'&&a[i+3]=='A')||(a[i]=='B'&&a[i+1]=='B'&&a[i+2]=='B'&&a[i+3]=='B')){
			a[i]=' ';
			a[i+1]=' ';
			a[i+2]=' ';
			a[i+3]=' ';
			i+=3;
		}
	}
	for(int i=1;i<=p;i++){
		if(a[i]=='A'){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					bit[k][n-j+1][1]=bit[j][k][0];
				}
			}
			swap(n,m);
			clean(n,m);
		}
		if(a[i]=='B'){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					bit[m-k+1][j][1]=bit[j][k][0];
				}
			}
			swap(n,m);
			clean(n,m);
		}
		if(a[i]=='C') {
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m/2;k++){
					swap(bit[j][m-k+1][0],bit[j][k][0]);
				}
			}
		}
		if(a[i]=='D') {
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=m;k++){
					swap(bit[n-j+1][k][0],bit[j][k][0]);
				}
			}
		}
	}
	/*
	2 3 2
1 2 3
4 5 6
A B
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",bit[i][j][0]);
		}
		printf("\n");
	}
	return 0;
}
