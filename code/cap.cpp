#include<bits/stdc++.h>
using namespace std;
int n,a[100],b[100];
int main(){
	freopen("cap.in","r",stdin);
	freopen("cap.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		if(a[i]>=10||b[i]>=20)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
