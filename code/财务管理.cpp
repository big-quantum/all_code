#include<bits/stdc++.h>
using namespace std;
float s,m;
int main(){
	for(int i = 1;i <= 12;i++){
		cin >> m;
		s = s + m;		
	}
	printf("$%0.2f\n",s / 12);
	return 0;		
}
