#include<bits/stdc++.h>
using namespace std;
int opt[35],n;
int main(){
	opt[1] = 1;
	opt[2] = 2;
	cin >> n;
	for(int i = 3;i <= n;i++)
		opt[i] = opt[i - 1] + opt[i - 2];
	cout << opt[n] << endl;
	return 0;
}

