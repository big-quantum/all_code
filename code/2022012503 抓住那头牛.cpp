#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	int x,minn;
}que[1000005];
bool space[100010];
void bfs(int n,int k){
	int front=1,rear=2;
	que[front].x=n;
	que[front].minn=0;
	space[n]=true;
	while(front<rear){
		int x=que[front].x,t=que[front].minn;
		if(x==k){
			cout<<t<<endl;
			return;
		}
		for(int i=1;i<=3;i++){
			if(i==1){
				int xx=x+1;
				if(xx>=0&&xx<100005&&space[xx]==false){
					que[rear].x=xx;
					que[rear].minn=t+1;
					space[xx]=true;
					rear++;
				}
			}
			if(i==2){
				int xx=x-1;
				if(xx>=0&&xx<100005&&space[xx]==false){
					que[rear].x=xx;
					que[rear].minn=t+1;
					space[xx]=true;
					rear++;
				}
			}
			if(i==3){
				int xx=x*2;
				if(xx>=0&&xx<100005&&space[xx]==false){
					que[rear].x=xx;
					que[rear].minn=t+1;
					space[xx]=true;
					rear++;
				}
			}
		}
		front++;
	}
}
int main(){
	cin>>n>>k;
	if(n>=k){
		cout<<n-k<<endl;
		return 0;
	}
	bfs(n,k);
	return 0; 
}
