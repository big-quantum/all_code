#include<bits/stdc++.h>
using namespace std;
string s;
bool yes = true;
int main(){
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if (i % 2 == 0 && s[i] == 'L'){
			yes = false;
			break;
		}	
		if (i % 2 == 1 && s[i] == 'R'){
			yes = false;
			break;
		}		
	}
	if (yes)	
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}


