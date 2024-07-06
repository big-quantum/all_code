#include<bits/stdc++.h>
using namespace std;
int m,n,num[15],cnt;

void shuchu(){
	cnt++;
	cout << cnt << ":";
	for(int k = 1;k <= n;k++)
		cout << num[k] << " ";
	cout << endl;
}
void dfs(int i){
	for(int j = 1;j <= m;j++)
		if (j > num[i - 1]){
			num[i] = j;
			if (i == n) shuchu();
			else dfs(i + 1);
			num[i] = 0;			
		}
}
int main(){
	cin >> m >> n;
	dfs(1);
	return 0;
}


