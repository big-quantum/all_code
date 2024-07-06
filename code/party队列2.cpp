#include<bits/stdc++.h>
using namespace std;
int m,n,k;
queue<int>g,l;
int main(){
	//freopen("party.in","r",stdin)
	//freopen("party.out","w",stdout)
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
		g.push(i);
	for(int i=1;i<=n;i++)
		l.push(i);
	for(int i=1;i<=k;i++){
		cout<<g.front()<<" "<<l.front()<<endl;
		g.push(g.front());
		l.push(l.front());
		g.pop();
		l.pop();
		
	}
	return 0;
} 
