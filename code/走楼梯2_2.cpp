#include<bits/stdc++.h>
using namespace std;
int n,opt[35];
int main(){
	cin >> n;
	opt[1] = 1;
	opt[2] = 1;
	for(int i = 3;i <= n;i++)
		opt[i] = min(opt[i - 1],opt[i - 2]) + 1; 
		//��i��¥��ֻ�ܴӵ�i-1�����i-2��¥������ 
	cout << opt[n] << endl;
	return 0;	
}
