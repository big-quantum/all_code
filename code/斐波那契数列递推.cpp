#include<bits/stdc++.h>
using namespace std;
int n,num[55];


int main(){
	cin >> n;
	num[1] = num[2] = 1;
	for(int i = 3;i <= n;i++)
		num[i] = num[i - 1] + num[i - 2];
	cout << num[n] << endl;		
	return 0;
}

