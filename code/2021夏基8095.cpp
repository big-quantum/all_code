#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	int n;
	cin>>n;
	getline(cin,a);
	for(int i=1;i<=n;i++)
	{
	 b="";
	 getline(cin,a);
	 for(int j=0;j<a.size();j++)
	 {
	  if(a[j]>='0'&&a[j]<='9')
	   {
		   int data=0;
		   while(a[j]>='0'&&a[j]<='9')	
		   {
		  	data=data*10+a[j]-'0';
		  	j++;
		    }
	    // b=b+char('A'-1+data);
	     b+='A'-1+data;
	    j--;
       }
	  else if(a[j]=='#') b=b+' ';
     }
	 cout<<b<<endl;	
	 }
 return 0;
 }

