#include<bits/stdc++.h>
using namespace std;
int n,num[25][25];
int main() {
	cin >> n;
	for(int i = 1; i <= (n + 1) / 2; i++)
		for(int j = 1; j <= (n + 1) / 2; j++) {
			num[i][j] = min(i,j);
			num[i][n + 1 - j] = num[i][j];
			num[n + 1 - i][j] = num[i][j];	
			num[n + 1 - i][n + 1 - j] = num[i][j];				
		}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			cout << setw(4) << num[i][j];
		cout << endl;
	}	
	return 0;
}
/*
1	1	1	1	1
1	2	2	2	1
1	2	3	2	1
1	2	2	2	1
1	1	1	1	1
*/
