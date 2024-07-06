#include<bits/stdc++.h>
using namespace std;
int n;
string s[105],tmp;
int main() {
	while(cin>>tmp) {
		n++;
		s[n]=tmp;
	}
	for(int i=1; i<n; i++)
		for(int j=i+1; j<=n; j++)
			if(s[i]>s[j])
				swap(s[i],s[j]);
	cout<<s[1]<<endl;
	for(int i=2; i<=n; i++)
		if(s[i]!=s[i-1])
			cout<<s[i]<<endl;
	return 0;
}
