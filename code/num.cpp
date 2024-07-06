#include<bits/stdc++.h>
using namespace std;
int k,a,b,c;
bool yes = false;
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin >> k;
	for(int i = 10000;i <= 30000;i++){
		a = i / 100;
		b = i / 10 % 1000;
		c = i % 1000;
		if (a % k == 0 && b % k == 0 && c % k == 0){
			yes = true;
			cout << i << endl;
		}
	}
	if (!yes)
		cout << "No" << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
