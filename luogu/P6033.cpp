#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n, ton[1000005];
int ans;
queue<int> q1, q2;

void read(int &x){ 
	int f = 1;
    x = 0;
    char s = getchar();
	while(s < '0' || s > '9'){
        if(s == '-') f = -1;
        s=getchar();
    }
	while(s>='0'&&s<='9'){
        x = x * 10 + s - '0';
        s = getchar();
    }
	x *= f;
}

signed main(){
    read(n);
    for(int i = 1; i <= n; i++){
        int tmp;
        read(tmp);
        ton[tmp]++;
    }
    for(int i = 1; i <= 1000000; i++){
        while(ton[i] != 0){
            ton[i]--;
            q1.push(i);
        }
    }
    for(int i = 1; i < n; i++){
        int x, y;
        if(q1.empty() || !q2.empty() && q1.front() > q2.front()){
            x = q2.front();
            q2.pop();
        } else {
            x = q1.front();
            q1.pop();
        }
        if(q1.empty() || !q2.empty() && q1.front() > q2.front()){
            y = q2.front();
            q2.pop();
        } else {
            y = q1.front();
            q1.pop();
        }
        q2.push(x + y);
        ans += x + y;
    }
    cout << ans << endl;

    return 0;
}