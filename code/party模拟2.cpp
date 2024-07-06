#include<bits/stdc++.h>
using namespace std;
int m,n,k,l = 0,g = 0;
int main(){
	freopen("party.in","r",stdin);	
	freopen("party.out","w",stdout);
	cin >> m >> n >> k;
	for(int i = 1;i <= k;i++){
		cout << g + 1 << " " << l + 1 << endl;
		g = (g + 1) % m;//下一位男士的编号 
		l = (l + 1) % n;//下一位女士的编号 
	}
	return 0;	
} 

