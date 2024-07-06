#include<bits/stdc++.h>
using namespace std;

int n;



void prime(int n){//2-n中的质数 O(n) P3383
    bool is_prime[n + 2];
    memset(is_prime, true, sizeof(is_prime));
    vector<int> prime;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]) prime.push_back(i);
        for(int p : prime){
            if(i * p > n) break;
            is_prime[i * p] = false;
            if(i % p == 0) break;
        }
    }
    for(int p : prime){
        cout << p << " ";
    }
}



int main(){


    return 0;
}