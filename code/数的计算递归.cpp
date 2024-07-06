#include<bits/stdc++.h>
using namespace std;
int n,ans;
void dfs(int n){
	ans++;
	for(int i = 1;i <= n / 2;i++)
		dfs(i);
}

int main(){
	cin >> n;
	dfs(n);
	cout << ans << endl;		
	return 0;
}
/*
6
6
16
26 126
36 136
*/
