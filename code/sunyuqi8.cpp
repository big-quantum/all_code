#include<bits/stdc++.h>
using namespace std;
int a,b;
int main() {
	for(int i = 1;i<=100;i++)
		if(i%2==1) a=a+i;
			else b=b+i;
	cout << a << endl;
	cout << b << endl;
	return 0;
}
