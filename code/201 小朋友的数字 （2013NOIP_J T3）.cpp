#include<bits/stdc++.h>
using namespace std;
int n,p;
struct node{
	int a;
	long long tmp,score,tmpscore;
}stu[100005];
long long maxscore;
int main(){
	cin>>n>>p;
	cin>>stu[1].a;
	stu[1].tmp=stu[1].a;
	stu[1].score=stu[1].tmp;
	maxscore=stu[1].score;
	for(int i=2;i<=n;i++){
		cin>>stu[i].a;
		long long sum=0,t=stu[i].a;
		for(int j=1;j<=i;j++){
			if(sum+stu[j].a>=0){
				sum+=stu[j].a;
			} else {
				sum=stu[j].a;
			}
			if(sum>t) t=sum;
		}
		stu[i].tmp=t;
		stu[i-1].tmpscore=stu[i-1].score+stu[i-1].tmp;		
		stu[i].score=max(stu[i-1].tmpscore,stu[i-2].score);
		stu[2].score=stu[1].tmp+stu[1].score;
		maxscore=max(maxscore,stu[i].score);
	}
	cout<<maxscore%p<<endl;
	return 0;
}
