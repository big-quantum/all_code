#include<bits/stdc++.h>
using namespace std;

int n, a[10005], ans;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        q.push(a[i]);
    }
    while(!q.empty() && q.size() > 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }
    cout << ans << endl;

    return 0;
}