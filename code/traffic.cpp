#include<bits/stdc++.h>
using namespace std;
int t,n,c,ans;
int main(){
	cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> c;
		ans = ans + 10 - c;		
	}
	cout << ans + 10 << endl;
	return 0;
} 
