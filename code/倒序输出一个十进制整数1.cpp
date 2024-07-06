#include<bits/stdc++.h>
using namespace std;

int n,num[100],L;

int main(){
	cin >> n;
	while(n){
		cout << n % 10;
		n /= 10;
	}	
	cout << endl;
	return 0;
}