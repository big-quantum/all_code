#include<bits/stdc++.h>
using namespace std;
int ch[305],ma,en,all[305],n,x[305];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch[i]>>ma>>en;
		all[i]=ch[i]+ma+en;
		x[i]=i;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			if(all[j]<all[j+1]||(all[j]==all[j+1]&&ch[j]<ch[j+1])||(all[j]==all[j+1]&&ch[j]==ch[j+1]&&x[j]>x[j+1])){
				swap(all[j],all[j+1]);
				swap(ch[j],ch[j+1]);
				swap(x[j],x[j+1]);
			}
	for(int i=1;i<=5;i++)
		cout<<x[i]<<" "<<all[i]<<endl;
	return 0; 
}
