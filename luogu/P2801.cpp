#include<bits/stdc++.h>
using namespace std;

int n, q, sq, st[1005], ed[1005], stk[1000005];
long long length[1000005], tap[1005], length_2[1000005];

int find(int s, int num){
    int left = st[s], right = ed[s];
    int mid, ans = 0;
    while (left <= right){
        mid = (left + right) / 2;
        if(length_2[mid] + tap[s] >= num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    ans += ed[s] - left + 1;
    return ans;
}

int main(){
    scanf("%d%d", &n, &q);
    sq = sqrt(n);
    for (int i = 1; i <= sq; i++){
        st[i] = sq * (i - 1) + 1;
        ed[i] = sq * i;
    }
    ed[sq] = n;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &length[i]);
        length_2[i] = length[i];
    }
    for(int i = 1; i <= sq; i++){
        for(int j = st[i]; j <= ed[i]; j++){
            stk[j] = i;
        }
        sort(length_2 + st[i], length_2 + ed[i] + 1);
    }

    for(int i = 1; i <= q; i++){
        char s;
        cin >> s;
        if(s == 'M'){
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            if(stk[x] == stk[y]){
                for(int j = x; j <= y; j++){
                    length[j] += w;
                    length_2[j] = length[j];
                }
                sort(length_2 + st[stk[x]], length_2 + ed[stk[x]] + 1);
            } else {
                for(int j = x; j <= ed[stk[x]]; j++){
                    length[j] += w;
                    length_2[j] = length[j];
                }
                sort(length_2 + st[stk[x]], length_2 + ed[stk[x]] + 1);
                for(int j = stk[x] + 1; j <= stk[y] - 1; j++){
                    tap[j] += w;
                }
                for(int j = st[stk[y]]; j <= y; j++){
                    length[j] += w;
                    length_2[j] = length[j];
                }
                sort(length_2 + st[stk[y]], length_2 + ed[stk[y]] + 1);
            }
        } else {
            int x, y, c;
            long long ans = 0;
            scanf("%d%d%d", &x, &y, &c);
            if(stk[x] == stk[y]){
                for(int j = x; j <= y; j++){
                    if(length[j] + tap[stk[j]] >= c){
                        ans++;
                    }
                }
            } else {
                for(int j = x; j <= ed[stk[x]]; j++){
                    if(length[j] + tap[stk[j]] >= c){
                        ans++;
                    }
                }
                for(int j = stk[x] + 1; j <= stk[y] - 1; j++){
                    ans += find(j, c);
                }
                for(int j = st[stk[y]]; j <= y; j++){
                    if(length[j] + tap[stk[j]] >= c){
                        ans++;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}