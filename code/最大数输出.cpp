#include<bits/stdc++.h>
using namespace std;
int a,b,c,boss;
int main(){
	cin >> a >> b >> c;
	boss = a;
	if (b > boss) boss = b;
	if (c > boss) boss = c;
	cout << boss << endl;
	return 0;
} 
