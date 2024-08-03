#include<bits/stdc++.h>
using namespace std;

int n, m, t;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		bool flag = false;
		if(m % 2 != 0 && n != 0){
			cout << "Yes" << endl;
			flag = true;
		} 
		if(m % 2 == 0 && n == 0){
			cout << "Yes" << endl;
			flag = true;
		}
		if(!flag) cout << "No" << endl;
	}
	return 0;
}
