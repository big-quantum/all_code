#include<bits/stdc++.h>
using namespace std;
int a,b;
char s;
int main(){
	cin>>a>>b>>s;
	switch(s){
		case'+':cout<<a+b<<endl;break;
		case'-':cout<<a-b<<endl;break;
		case'*':cout<<a*b<<endl;break;
		case'/':if(b!=0)cout<<a/b<<endl;
		else cout<<"Divided by zero!"<<endl;break;
		default:cout<<"Invalid operator!"<<endl;
	}
	return 0;
}
