#include<bits/stdc++.h>
using namespace std;
/*struct node{
	int num,name;
};
struct mapnode{
	int c[1005]; 
};
map<int,mapnode> mapp; 
queue<node>q;*/
map<int,int>mapp;
queue<int>q;
int n,m;
int main(){
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int tmp;
			cin>>tmp;
			mapp[tmp]=i;
		}
	}
	string s;
	for(int i=1;i<=m;i++){
		cin>>s;
		if(s=="ENQUEUE"){
			int data;
			cin>>data;
			if(!q.empty()){
				for(int j=1;j<=q.size();j++){
					if(mapp[q.front()]!=mapp[data]&&mapp[q.back()]==mapp[data]){
						q.push(data);
					} else {
						q.push(q.front());
						q.pop(); 
					}
				}
			} else {
				q.push(data);
			}
		} else {
			cout<<q.front()<<endl;
			q.pop();
		}
	}
	return 0;
}/*
2 12
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
*/
