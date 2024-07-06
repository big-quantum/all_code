#include<bits/stdc++.h>
using namespace std;
int n,age[105];
float a,b,c,d;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>age[i];
		if(age[i]<=18)	a++;
		else if(age[i]>=19&&age[i]<=35) b++;
			 else if(age[i]>=36&&age[i]<=60) c++;
			      else 	d++;
	}
	cout<<fixed<<setprecision(2)<<a*100.00/n<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<b*100.00/n<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<c*100.00/n<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<d*100.00/n<<"%"<<endl;
	return 0;
}
