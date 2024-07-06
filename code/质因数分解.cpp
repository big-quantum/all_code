#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
	cin >> n;
	for(int i = 2;i < n;i++)
		if (n % i == 0){
			ans = n / i;
			break;
		}
	cout << ans << endl;
	return 0;
}

/* 

21 = 3 * 7
35 = 5 * 7
*/
