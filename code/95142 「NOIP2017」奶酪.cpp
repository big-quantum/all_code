#include<bits/stdc++.h>
using namespace std;
int n,h,r,t,rr;
struct node{
	double x,y,z;
	bool visit;
}hole[1005];
queue<int>que;
double dist(double xx,double yy,double zz){
	return sqrt(xx+yy+zz);
}
double dd(double a){
	return a*a;
}
double ab(double a){
	if(a>=0) return a;
	else return -1*a;
}
void clean(){
	while(!que.empty()) que.pop();
	for(int i=1;i<=n;i++){
		hole[i].x=0;
		hole[i].y=0;
		hole[i].z=0;
		hole[i].visit=false;
	}
}
void bfs(){
	while(!que.empty()){
		if(r+hole[que.front()].z>=h){
			cout<<"Yes"<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			double dx,dy,dz;
			if(hole[i].visit) continue;
			dx=ab(hole[que.front()].x-hole[i].x);
			if(dx>rr) continue;
			dy=ab(hole[que.front()].y-hole[i].y);
			if(dy>rr) continue;
			dz=ab(hole[que.front()].z-hole[i].z);
			if(dz>rr) continue;
			if(dist(dd(dx),dd(dy),dd(dz))<=rr){
				que.push(i);
				if(r+hole[i].z>=h){
					cout<<"Yes"<<endl;
					return;
				}
				hole[i].visit=true;
			}
		}
		que.pop();
	}
	cout<<"No"<<endl;
	return;
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>h>>r;
		rr=2*r;
		for(int j=1;j<=n;j++){
			cin>>hole[j].x>>hole[j].y>>hole[j].z;
			if(r>=hole[j].z){
				que.push(j);
				hole[j].visit=true;
			}
		}
		bfs();
		clean();
	}
	return 0;
} 
