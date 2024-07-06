#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if (s[i] == '1')
			cout << '9';
	    if (s[i] == '9')
			cout << '1';		
		if (s[i] != '1' && s[i] != '9')
			cout << s[i];
	}
	cout << endl;
	return 0;
}
