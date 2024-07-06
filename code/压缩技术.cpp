#include<bits/stdc++.h>
using namespace std;
int n,x,y,num,Map[205][205],f;
int main(){
	cin>>n;
	while(cin>>num){
		for(int i = 1;i<=num;i++){
			Map[x][y] = f;
			y++;
			if(y==n){
				x++;
				y = 0;
			}
		}
		f = 1  - f;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			cout<<Map[i][j];
		cout<<endl;
	}
}
