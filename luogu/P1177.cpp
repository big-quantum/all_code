#include<bits/stdc++.h>
using namespace std;

int n, a[100005];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a, a + n + 1);
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }

    return 0;
}