#include<bits/stdc++.h>
using namespace std;
int n,num[55];

int dfs(int n){
	if (n == 1 || n == 2)
		return 1;
	return dfs(n - 1) + dfs(n - 2);
}
int main(){
	cin >> n;
	cout << dfs(n) << endl;
	return 0;
}

