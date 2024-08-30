#include<bits/stdc++.h>
using namespace std;

int pos[10005], num[10005], n, cnt;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        pos[num[i]] = i;
    }
    for(int k = 1; k <= 100; k++)
    for(int i = 1; i <= n; i++){
        if(num[i] != i){
            cnt++;
            swap(num[i], num[num[i]]);
            //swap(pos[num[i]], pos[i]);
        }
    }
    cout << cnt << endl;
    return 0;
}