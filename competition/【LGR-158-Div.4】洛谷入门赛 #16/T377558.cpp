#include<bits/stdc++.h>
using namespace std;

int T, ans;
string s, t;

int main() {	
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> s >> t;
	}
	
	int length = t.size();
	int slength = s.size();
	for(int i = 0; i < min(length, slength - length + 1); i++){
		string tmp = s.substr(slength - length + i, length - i) + s.substr(0, i);
		if(tmp == t) ans++;
	}
	cout << ans << endl;
	return 0;
}
