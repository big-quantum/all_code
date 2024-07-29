#include<bits/stdc++.h>
using namespace std;

int n, m1, m2, cnt;
vector<pair<int, int>> nation, global;


bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
} 

void solve(vector<pair<int, int>>& flight, vector<int>& bridge){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tim;
	priority_queue<int, vector<int>, greater<int>> can;
	for(int i = 1; i <= n; i++){
		can.push(i);
	}

	for(auto i : flight){
		while (!tim.empty() && tim.top().first < i.first){
			can.push(tim.top().second);
			tim.pop();
		}
		if(!can.empty()){
			int gate = can.top();
			can.pop();
			tim.push(make_pair(i.second, gate));
			bridge[gate]++;
		}
	}
	for(int i = 1; i <= n; i++){
		bridge[i] += bridge[i - 1];
	}
}

int main(){
	cin >> n >> m1 >> m2;
	vector<int> nation_ans(n + 5), global_ans(n + 5);

	if(m2 + m1 <= n){
		cout << m2 + m1 << endl;
		return 0;
	}
	
	for(int i = 1; i <= m1; i++){
		int f, t;
		cin >> f >> t;
		nation.push_back(make_pair(f, t));
	}
	sort(nation.begin(), nation.end(), cmp);
	solve(nation, nation_ans);
	
	for(int i = 1; i <= m2; i++){
		int f, t;
		cin >> f >> t;
		global.push_back(make_pair(f, t));
	}
	sort(global.begin(), global.end(), cmp);
	solve(global, global_ans);
	
	int ans = -1, tmp;
	for(int i = 0; i <= n; i++){
		ans = max(ans, nation_ans[i] + global_ans[n - i]);
	}
	cout << ans << endl;
	return 0;
}
