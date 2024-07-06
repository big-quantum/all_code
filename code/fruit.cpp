#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,num;
}; 
queue<node> a,a2;
int n,flag=2,t,cnt;
bool used[200005];
int main(){
	//freopen("fruit.in","r",stdin);
	//freopen("fruit.out","w",stdout);
	scanf("%d",&n); 
	cnt=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&t); 
		if(t!=flag){
			a.push(node{i,i,t});
			flag=t;
		} else {
			a.back().r++;
		}
	}
	while(cnt){
		int len=a.size(),flag=2;
		for(int i=1;i<=len;i++){
			node tmp=a.front();
			a.pop();
			while(used[tmp.l]&&tmp.l<=tmp.r) tmp.l++;
			if(tmp.l>tmp.r) continue;
			printf("%d ",tmp.l);
			cnt--;
			used[tmp.l]=true;
			tmp.l++;
			if(tmp.l<=tmp.r) a2.push(tmp);
		}
		printf("\n");
		while(a2.size()){
			node tmp=a2.front();
			a2.pop();
			while(a2.size()){
				if(a2.front().num==tmp.num){
					tmp.r=a2.front().r;
					a2.pop();
				} else {
					break;
				}
			}
			a.push(tmp);
		}
	}
	return 0;
}
