#include<bits/stdc++.h>
using namespace std;

int n, length[3000005], ans[3000005];
stack<int> sta;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &length[i]);
    }
    for (int i = 1; i <= n; i++) {
        while(!sta.empty() && length[i] > length[sta.top()]){
            ans[sta.top()] = i;
            sta.pop();
        }
        sta.push(i);
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}