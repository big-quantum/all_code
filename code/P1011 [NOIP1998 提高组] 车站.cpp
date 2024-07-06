#include<bits/stdc++.h>
using namespace std;
int a,n,m,x;
int dfs(int n,int a){
	if (n == 1 || n == 2)
		return a;
	return dfs(n - 1) + dfs(n - 2);
}
int main(){
	cin>>a>>n>>m>>x;
	
	return 0;
} 
