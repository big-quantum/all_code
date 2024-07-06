#include<bits/stdc++.h>
using namespace std;
string s;
int ans1,ans2,num;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] - '0' != num)
			ans1++;
		num = 1 - num;
	}
	num = 1;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] - '0' != num)
			ans2++;
		num = 1 - num;
	}
	cout << min(ans1,ans2) << endl;
	return 0;
}




