#include<bits/stdc++.h>
using namespace std;
string name[21]; 
int a[21],n,k;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>name[i]>>a[i];
	for(int i=n-1;i>=1;i--)
		for(int j=0;j<i;j++)
			if(a[j]<a[j+1]||a[j]==a[j+1]&&name[j]>name[j+1]){
			swap(name[j],name[j+1]);
			swap(a[j],a[j+1]);
			}
	for(int i=0;i<n;i++)
		cout<<name[i]<<" "<<a[i]<<endl;
	return 0;
}
