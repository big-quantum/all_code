#include<bits/stdc++.h>
using namespace std;
int m,n,k,l = 1,g = 1;
int main(){
	freopen("party.in","r",stdin);	freopen("party.out","w",stdout);
	cin >> m >> n >> k;
	for(int i = 1;i <= k;i++){
		cout << g << " " << l << endl;
		g++;//下一位男士的编号 
		if (g == m + 1)
			g = 1; 
		l++;//下一位女士的编号 
		if (l == n + 1)
			l = 1;		
	}
	return 0;	
} 
