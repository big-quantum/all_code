#include<bits/stdc++.h>
using namespace std;
float a,s,n;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a;
		s = s + a;		
	}
	printf("%.0lf %0.5f\n",s,s / n);
	return 0;		
}
