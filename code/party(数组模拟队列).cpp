#include<bits/stdc++.h>
using namespace std;
int m,n,k,l[2005],g[2005],lr,gr;

int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin >> m >> n >> k;
	for(int i = 1;i <= m;i++)//数组模拟队列 
		l[i] = i;//表示男士 
	lr = m + 1;
	for(int i = 1;i <= n;i++)
		g[i] = i;//表示女士 
	gr = n + 1;
	for(int i = 1;i <= k;i++){
		cout << l[i] << " " << g[i] << endl;	
		l[lr] = l[i];//男士当前队头元素复制到队尾
		lr++;	
		g[gr] = g[i];
		gr++;		
	}
	return 0;	
} 
 
 
