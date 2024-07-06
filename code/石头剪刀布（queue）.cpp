#include<bits/stdc++.h>
using namespace std;
int n,na,nb,num,fa,fb,ansa,ansb;
queue<int>qa,qb; 
int main(){
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++){
		cin>>num;
		qa.push(num);
	}
	for(int i=0;i<nb;i++){
		cin>>num;
		qb.push(num);
	}
	for(int i=1;i<=n;i++){
		fa = qa.front();
		fb = qb.front();
		if(fa == 0&&fb == 2)
			ansa++;
		if(fa == 2&&fb == 5)
			ansa++;
		if(fa == 5&&fb == 0)
			ansa++;
		if(fb == 0&&fa == 2)
			ansb++;
		if(fb == 2&&fa == 5)
			ansb++;
		if(fb == 5&&fa == 0)
			ansb++;
		qa.push(fa);
		qb.push(fb);
		qa.pop();
		qb.pop();
	}
	if(ansa>ansb)
		cout<<"A"<<endl;
	if(ansa==ansb)
		cout<<"draw"<<endl;
	if(ansa<ansb)
		cout<<"B"<<endl;	
} 
