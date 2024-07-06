#include<bits/stdc++.h>
using namespace std;
string s;
int ans1,ans2;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if (i % 2 == 0 && s[i] - '0' != 0)
			ans1++;
		if (i % 2 == 1 && s[i] - '0' != 1)
			ans1++;
	}
	for(int i = 0; i < s.size(); i++) {
		if (i % 2 == 0 && s[i] - '0' != 1)
			ans2++;
		if (i % 2 == 1 && s[i] - '0' != 0)
			ans2++;
	}
	cout << min(ans1,ans2) << endl;
	return 0;
}
