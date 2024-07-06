#include<bits/stdc++.h>
using namespace std;

int n,jw,s[10005];
int main(){
	cin >> n;
	s[1] = 1;
	for(int i = 1;i <= n;i++){
		jw = 0;
		for(int j = 1;j<= 5000;j++){
			jw = jw + s[j] * 2;
			s[j] = jw % 10;
			jw = jw / 10;
		}		
	}
	int j;
	for(j = 5000;j >= 1;j--)
		if (s[j])
			break;
	for(int i = j;i >= 1;i--)
		cout << s[i];
	cout << endl;
	return 0;
}
