#include<bits/stdc++.h>
using namespace std;
struct window{
	int left,right,up,down;
}one,two,tmp;
int main(){
	cin>>one.left>>one.right>>one.up>>one.down;
	cin>>two.left>>two.right>>two.up>>two.down;
	tmp.left=max(one.left,two.left); 
	tmp.right=min(one.right,two.right);
	tmp.up=max(one.up,two.up);
	tmp.down=min(one.down,two.down);
	int s=(tmp.right-tmp.left)*(tmp.down-tmp.up);
	if((tmp.right<=tmp.left)||(tmp.down<=tmp.up)) s=0;
	cout<<s<<endl;
	return 0;
}

