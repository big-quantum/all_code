#include<bits/stdc++.h>
using namespace std;
int n,a;
float s;
int main(){
	cin >> n; 
	for(int i = 1;i <= n;i++){
		cin >> a;
		s = s + a;		
	}
	printf("%0.2f\n",s / n);
	return 0;		
}
