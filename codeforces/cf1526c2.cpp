#include<bits/stdc++.h>
using namespace std;

long long n, tmp, ans, cnt;
priority_queue<long long> q;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        if(tmp >= 0){
            cnt += tmp;
            ans++;
        } else {
            q.push(-tmp);
            cnt += tmp;
            ans++;
            if(cnt < 0){
                cnt += q.top();
                q.pop();
                ans--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}