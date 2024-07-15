#include<bits/stdc++.h>
using namespace std;

deque<pair<int, int> > q1, q2;//q1¼õ£¬q2Ôö 
int n, a[1000005], k, ans[1000005], cnt = 1;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		pair<int, int> tmp;
		tmp.first = a[i];
		tmp.second = i;
		while(!q1.empty() && a[i] >= q1.back().first) q1.pop_back();
		while(!q2.empty() && a[i] <= q2.back().first) q2.pop_back();
		q1.push_back(tmp);
		q2.push_back(tmp);
		while(i - k >= q1.front().second) q1.pop_front();
		while(i - k >= q2.front().second) q2.pop_front();
		if(i >= k){
			cout << q2.front().first << " ";
			ans[cnt++] = q1.front().first;
		}
	}
	cout << endl;
	for(int i = 1; i < cnt; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
