#include<bits/stdc++.h>
using namespace std;
int n;
void mov(int n,char X,char Y,char Z){
	if (n == 1)
		cout<<X<<" "<<"To"<<" "<<Z<<endl;
	else{
		mov(n-1,X,Z,Y);
		cout<<X<<" "<<"To"<<" "<<Z<<endl;
		mov(n- 1,Y,X,Z);
	}
}
int main(){
	cin>>n;
	mov(n,'A','B','C');
	return 0;
}
