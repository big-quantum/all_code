#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin >> a >> b >> c;
	cout << max(c - b - 1,b - a - 1) << endl;	
	return 0;
}
