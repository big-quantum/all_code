#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
//dp/³Ë·¨Ô­Àí 
int n, ans = 1; 
char s[250005];

int main(){
	cin >> n;
	int ss = 0; 
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		if(s[i] != s[i - 1]) ss++;
		else {
			ans = (ss / 2 + ss % 2) * ans % mod;
			ss = 1;
		}
	}
	ans = (ss / 2 + ss % 2) * ans % mod;
	cout << ans << endl;
	
	return 0;
}
