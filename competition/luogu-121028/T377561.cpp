#include<bits/stdc++.h>
using namespace std;

int T, ans, n, a, b, c, d, e, f;

int main() {	
	cin >> T;
	for(int q = 1; q <= T; q++){
		cin >> n >> a >> b >> c >> d >> e >> f;
		for(int i = 0; i <= 1e8; i++){
			if(a == d && b == e && c == f){
				cout << ans << endl;
				ans = 0;
				break;
			}
			if(c != b * 10 + 1){
				c++;
				ans++;
			} else {
				c = 0;
				if(++b == a + 1){
					b = 0;
					if(++a == n){
						a = 0;
					}
				}
			}
		}
	}
	return 0;
}
