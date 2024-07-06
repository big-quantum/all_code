#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main() {
	cin >> a >> b >> c;
	if(a+b>c&&a+c>b&&c+b>a) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
