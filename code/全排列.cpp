#include<bits/stdc++.h>
using namespace std;

int n,num[25],t;
bool used[25];
void Print(){
	t++;
	cout << "No." << t << ":";
	for(int i = 1;i < n;i++)
		cout << num[i] << " ";
	cout << num[n] << endl;
}
void dfs(int i){//生成第i个数 
	for(int j = 1;j <= n;j++)
		if (!used[j]){
			num[i] = j;
			used[j] = true;
			if (i == n)
				Print();
			else
				dfs(i + 1);
			used[j] = false;
			num[i] = 0;
		}
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
}


/*
123
132
213
231
312
321
*/
