#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int big(int a,int b,int c){
	int r = max(a,b);
	r = max(r,c);
	return r;	
}
int main(){
	cin >> a >> b >> c;
	cout << big(a,b,c) << endl;
	return 0;	
}
