#include<bits/stdc++.h>
using namespace std;
int f[55][55][55][55],a[55][55],n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
		}
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                	if(i==k&&j==l){
                		f[i][j][k][l]-=a[i][j];
					}
				}
            }
        }
	}
    cout<<f[n][m-1][n-1][m]<<endl;
    return 0;
}

