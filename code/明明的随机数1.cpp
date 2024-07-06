#include<bits/stdc++.h>
using namespace std;
set<int> a;
int main(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m; 
		a.insert(m); 
	}
	int lenth=a.size(); 
	cout<<lenth<<endl;
	set<int>::iterator it; 
	for(it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	return 0;
} 
