#include<bits/stdc++.h>
using namespace std;
int n, even, odd;
int main(){
    cin >> n;
    for(int i = 0; i < 32; i++){
        if(n & 1 == 1){
            if(i % 2 == 0) even++;
            else odd++;
        }
        n >>= 1;
    }
    cout << even << " " << odd << endl;

    return 0;
}