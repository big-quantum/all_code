#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
//char a[30]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z},n[15];
int main(){
	string s;
	for(int i=1;i<=3;i++){
		bool flag=false; 
		for(int j=1;j<=6;j++){
			Sleep(1000);
			srand((unsigned int)time(NULL));
			int ret=rand()%10;
			if(ret==4&&!flag){
				s+=ret;
				flag==true;
			} else {
				if(ret==1||ret==3||ret==5||ret==7||ret==9){
					Sleep(1000);
					srand((unsigned int)time(NULL));
					ret=rand()%26;
					char tmp='a'+ret;
					s+=tmp;
				} else {
					Sleep(1000);
					srand((unsigned int)time(NULL));
					ret=rand()%26;
					char tmp='A'+ret;
					s+=tmp;
				}
			}
		}
		s+='-';
	}
	//srand(unsigned int)time(NULL);
	cout<<s<<endl;
	/*cout<<1<<endl;
	Sleep(1000);
	cout<<2<<endl;*/
	return 0;
} 
