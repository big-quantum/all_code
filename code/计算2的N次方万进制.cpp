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
			s[j] = jw % 10000;
			jw = jw / 10000;
		}		
	}
	int j;
	for(j = 5000;j >= 1;j--)
		if (s[j])
			break;
	cout << s[j]; 
	for(int i = j - 1;i >= 1;i--){
		if (s[i] < 1000)
			cout << 0;
		if (s[i] < 100)
			cout << 0;
		if (s[i] < 10)
			cout << 0;
		cout << s[i];
	}
	
	cout << endl;
	return 0;
}
