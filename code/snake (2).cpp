#include<bits/stdc++.h>
using namespace std;
int a[25][25],n,b;
int main(){
	cin>>n;
	b=1; 
	for(int i=1;i<=n;i++){
		if(i%2==1){
			int j=1;
			for(int k=i;k>=1;k--){
				a[k][j]=b;
				b++;
				a[n+1-k][n+1-j]=n*n+1-a[k][j];
				j++;
			}
		} else {
			int j=i;
			for(int k=1;k<=i;k++){
				a[k][j]=b;
				b++;
				a[n+1-k][n+1-j]=n*n+1-a[k][j];
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
