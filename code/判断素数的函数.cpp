#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int n){
	if (n < 2)
		return false;
	for(int i = 2;i < n;i++)
		if (n % i == 0)
			return false;
	return true;
}
int main(){
	cin >> n;
	if (check(n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;	
}
