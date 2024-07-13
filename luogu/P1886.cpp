#include<bits/sdtc++.h>
using namespace std;

deque<int> q1, q2;
int n, a[1000005], k;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++){
		if(q1.empty()){
			q1.push(a[i]);
		}
		if(q1.back() < a[i]){
			q1.push_back(a[i]);
		} else {
			while(q1.back() >= a[i]) q1.pop_back();
			q1.push_back(a[i]);
		}
	}
	for(int i = k; i <= n; i++){
		cout << q2.back() << " ";
	}
	for(int i = 1; i <= k; i++){
		if(q2.empty()){
			q2.push(a[i]);
		}
		if(q1.back() < a[i]){
			q1.push_back(a[i]);
		} else {
			while(q1.back() >= a[i]) q1.pop_back();
			q1.push_back(a[i]);
		}
		if(q2.back() > a[i]){
			q2.push_back(a[i]);
		} else {
			while(q2.back() <= a[i]) q2.pop_back();
			q2.push_back(a[i]);
		}
	}
	for(int i = k; i <= n; i++){
		cout << q2.back() << " ";
	}
	return 0;
}
