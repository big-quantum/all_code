#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
bool p[100005];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		if(!p[(a + b) % n]){
			p[(a + b) % n] = true;
			cnt++;
		}
	}
	cout << n * m << endl;
	for(int i = 0; i < n; i++){
		if(cnt < m || p[i]){
			if(!p[i]) cnt++;
			for(int j = 1; j <= n; j++){
				cout << j << " " << (i - j + 2 * n - 1) % n + 1 << endl;
			}
		}
	}
	return 0;
}
