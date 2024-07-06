#include<bits/stdc++.h>
using namespace std;
int n,num[3005],s[3005];
bool yes = true;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	for(int i = 1;i < n;i++)
		s[i] = abs(num[i] - num[i + 1]);
	sort(s + 1,s + n);
	for(int i = 1;i < n;i++)
		if(s[i] != i) {
			yes = false;
			break;
		}
	if (yes)
		cout << "Jolly" << endl;
	else
		cout << "Not jolly" << endl;
	return 0;
} 
