#include<bits/stdc++.h>
using namespace std;
int n,num[10][10],t;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) {
			t++;
			num[i][j] = t;		
		}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++)
			cout << setw(5) << num[i][j];
		cout << endl;
	}
	return 0;		
}
