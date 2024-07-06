#include<bits/stdc++.h>
using namespace std;
int num[105],n,m,t;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>num[i];
	for(int i=1; i<n; i++)
		for(int j=i+1; j<=n; j++)
			if(num[i]>num[j])
				swap(num[i],num[j]);
	for(int i=1; i<=n; i++)
		if(num[i]!=num[i-1])
			m++;
	cout<<m<<endl;
	for(int i=1; i<=n; i++)
		if(num[i]!=num[i-1]) {
			t++;
			if(t<m)
				cout<<num[i]<<" ";
			else
				cout<<num[i]<<endl;
		}
	return 0;
}
