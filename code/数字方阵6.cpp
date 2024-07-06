#include<bits/stdc++.h>
using namespace std;
int num[25][25],n,step;
int main(){
	cin >> n;
	for(int k=1;k<=(n+1)/2;k++)
	step++;
	for(int i = k;i <= n;i++)//i是行 
		for(int j = k;j <= n;j++){//j是列 
			num[i][j] = step;
		}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			cout << setw(4) << num[i][j];
		cout << endl;
	}
	return 0;
}
/*
1 1 1 1 1
1 2 2 2 1
1 2 3 2 1
1 2 2 2 1
1 1 1 1 1
*/
