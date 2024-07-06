#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int que[100005];
int minn[100005];
int bfs(int m){
	int front=0,rear=1,t=1;
	que[front]=m;
	while(front<rear){
		for(int i=1;i<=3;i++){
			if(i==1){
				int ww=que[front]+1;
//				cout<<ww<<" ";
				if(minn[ww]==0&&ww>0&&ww<=100000){
					que[rear]=ww;
					minn[ww]=t;
					rear++;
				}
			}
			if(i==2){
				int ww=que[front]-1;
//				cout<<ww<<" ";
				if(minn[ww]==0&&ww>=0){
					que[rear]=ww;
					minn[ww]=t;
					rear++;
				}
			}
			if(i==3){
				int ww=que[front]*2;
//				cout<<ww<<" ";
				if(minn[ww]==0&&ww<=100000){
					que[rear]=ww;
					minn[ww]=t;
//					cout<<t<<" "; 
					rear++;
				}
			}
			t++;
		}
		front++;
	}
}
int main(){
	cin>>n>>k;
	bfs(n);
	if(n==k){
		cout<<0<<endl;
		return 0;
	}
//	for(int i=0;i<=100000;i++){
//		cout<<minn[i]<<" "; 
//	}
	cout<<minn[k]<<endl;
	return 0; 
}
