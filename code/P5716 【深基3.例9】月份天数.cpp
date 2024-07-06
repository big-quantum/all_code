#include<bits/stdc++.h>
using namespace std;
int year,month,days[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	cin>>year>>month;
	if(year%4==0&&year%100!=0||year%400==0)days[2]++;
	cout<<days[month];
	return 0;	
}

