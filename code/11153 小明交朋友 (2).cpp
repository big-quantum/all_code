#include<bits/stdc++.h>
using namespace std;
int a[105][105],q[10010][2],x,y,n;
struct node{
	int num,step;	
}que[50005];
bool p[105];
int bfs(int aa,int b){
	int front=0,rear=1;
	que[front].num=aa;
	que[front].step=0;
    while(front<rear){
		for(int i=1;i<=n;i++){
			if(a[que[front].num][i]){
				que[rear].num=i;
				que[rear].step=que[front].step+1;
				a[i][que[front].num]=0;
				if(i==b) {
				 return que[rear].step-1;
				}
				rear++;
			}
		}
		front++;
	}
	return que[rear].step; 
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<bfs(x,y)<<endl;;
	return 0;
}
