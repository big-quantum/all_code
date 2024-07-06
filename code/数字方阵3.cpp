#include<bits/stdc++.h>
using namespace std;
int num[25][25],n,step;
int main(){
	cin >> n;
	for(int j = 1;j <= n;j++)
		for(int i = 1;i <= n;i++){
			step++;
			num[i][j] = step;
		}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			cout << setw(4) << num[i][j];
		cout << endl;
	}
	return 0;
}
