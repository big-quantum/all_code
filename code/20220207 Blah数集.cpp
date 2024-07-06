#include<bits/stdc++.h>
using namespace std;
queue<long long> q,q1,q2;
int a,n,cnt;
int main(){
	cin>>a>>n;
	q.push(a);
	while(cnt+1!=n){
		q1.push(q.front()*2+1);
		q2.push(q.front()*3+1);
		q.pop();
		if(q1.front()<q2.front()){
			q.push(q1.front());
			q1.pop();
		} else {
			if(q1.front()>q2.front()){
				q.push(q2.front());
				q2.pop();
			} else {
				q.push(q1.front());
				q1.pop();
				q2.pop();
			}
		}
		cnt++;
	}
	cout<<q.front()<<endl;
	return 0;
} 
