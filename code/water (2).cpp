#include<bits/stdc++.h>
using namespace std;
int h,s,n;
string d;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>h>>s;
	cin>>d;
	//getline(cin,d);
	n=d.size();
	cout<<n<<" ";
	for(int i=0;i<=n-1;i++){
		if(d[i]=='u'&&s!=0) s--;
		if(d[i]=='d'&&s!=h) s++;
		cout<<s<<" ";
	}
	cout<<endl;
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
