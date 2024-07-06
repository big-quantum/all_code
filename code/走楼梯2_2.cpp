#include<bits/stdc++.h>
using namespace std;
int n,opt[35];
int main(){
	cin >> n;
	opt[1] = 1;
	opt[2] = 1;
	for(int i = 3;i <= n;i++)
		opt[i] = min(opt[i - 1],opt[i - 2]) + 1; 
		//第i级楼梯只能从第i-1级或第i-2级楼梯走来 
	cout << opt[n] << endl;
	return 0;	
}
