#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int n){
	int num = n;
	int revnum = 0;
	while(num){
		revnum = revnum * 10 + num % 10;
		num /= 10;
	}
	return n == revnum;	
}
int main(){
	cin >> n;	
	if (check(n))
		cout << "Yes" << endl;
	else
		cout<<"No"<<endl;
}
