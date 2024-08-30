#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p, num;
        cin >> p;
        if(p == 1){
            cin >> num;
            q.push(num);
        }
        if(p == 2) cout << q.top() << endl;
        if(p == 3) q.pop();
    }


    return 0;
}