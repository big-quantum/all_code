#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t;
bool monkey[305];
int main(){
	cin>>n>>m;
	while(n*m){
		i=0;
		j=0;
		t=n;
		memset(monkey,1,sizeof(monkey));
		while(t>1){
			i++;
			if(i==n+1)
				i=1;
			if(monkey[i]){
				j++;
				if(j==m){
					monkey[i]=false;
					t--;
					j = 0;
				}
			}
		} 
		for(int i=1;i<=n;i++)
			if(monkey[i])
				cout<<i<<endl; 
		cin>>n>>m;
	}
	return 0;
} 
