#include<bits/stdc++.h>
using namespace std;
queue<long long> q;
int n,s[10005];
int main(){
	cin>>n;
	for(int i=n;i>1;i--){
		q.push(i);
		for(int j=1;j<=i;j++){
			q.push(q.front());
			q.pop();
		} 
	}
	q.push(1);
	for(int i=1;i<=n;i++){
		s[i]=q.front();
		q.pop();
	}
	for(int i=n;i>=1;i--){
		cout<<s[i]<<" ";
	}
	return 0;
} 
