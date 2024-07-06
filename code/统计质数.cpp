#include<bits/stdc++.h>
using namespace std;
int n;
int p[1000005],s[1000005];
void Make_t(){
	for(int i = 2; i <= 1000000; i++)
		p[i] = 1;
	for(int i = 2; i <= 1000000; i++)
		if (p[i])
			for(int j = 2; j <= 1000000 / i; j++)
				p[i * j] = 0;	
}
int main() {
	cin >> n;
	Make_t();
	for(int i = 1;i <= 1000000;i++)
	   s[i] = s[i - 1] + p[i];
	for(int i = 1;i <= n;i++){
		int a,b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << endl;
	}	
	return 0;
}



