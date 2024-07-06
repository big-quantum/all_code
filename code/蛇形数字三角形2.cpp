#include<bits/stdc++.h>
using namespace std;
int n,num[35][35],step;
int main(){
	cin>>n;
	for(int k=1;k<=n;k++)
		if (k%2==0)
			for(inti = 1; i <= k; i++) {
				step++;
				int j = k + 1 - i;
				num[i][j] = step;
			}
		else
			for(int i = k; i >= 1; i--) {
				step++;
				int j = k + 1 - i;
				num[i][j] = step;
			}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n + 1 - i; j++)
			cout << setw(5) << num[i][j];
		cout << endl;
	}
	return 0;
}
