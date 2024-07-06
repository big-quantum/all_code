#include<bits/stdc++.h>
using namespace std;

int n,num[100],L;
int main(){
	cin >> n;
	if (n == 0) 
		cout << 0;
	while(n){
		L++;
		num[L] = n % 10;
		n /= 10;
	}
	for(int i = 1;i <= L;i++)
		cout<<num[i];
	return 0;
}




