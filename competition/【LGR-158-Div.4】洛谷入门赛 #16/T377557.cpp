#include<bits/stdc++.h>
using namespace std;

int n, m, w[200005], s[200005], ans;

int main() {
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	sort(w, w + m + 1);
	
	for(int i = 1; i <= n + 1; i++){
		if(w[i] > n) break;
		if(s[w[i]] < 200) ans++;
	}
	
	cout << ans << endl;
	return 0;
}
