#include<bits/stdc++.h>
using namespace std;

int n, k, num[100005], ans;
deque<int> que;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if(!que.empty() && i - que.front() >= k){
            que.pop_front();
        }
        while(!que.empty() && num[que.back()] < num[i]) {
            que.pop_back();
        }
        que.push_back(i);
        if(i > k - 1) {
            cout << num[que.front()] << " ";
        }
    }

    return 0;
}