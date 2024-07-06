#include<bits/stdc++.h>
using namespace std;
int a[25][25],n,b;
int main(){
	cin>>n;
	b=1; 
	for(int k=1;k<=n;k++){
		if(k%2==0){
			int j=1;
			for(int i=k;i>=1;i--){
				a[i][j]=b;
				b++;
				a[n+1-i][n+1-j]=n*n+1-a[i][j];
				j++;
			}
		} else {
			int j=k;
			for(int i=1;i<=k;i++){
				a[i][j]=b;
				b++;
				a[n+1-i][n+1-j]=n*n+1-a[i][j];
				j--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
