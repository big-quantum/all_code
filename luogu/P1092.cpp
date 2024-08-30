#include<bits/stdc++.h>
using namespace std;

int n, num[30];

bool check(){

}

void dfs(int cnt){
    if(cnt == n && check()){
        for(int i = 0; i < n; i++){
            cout << num[i] << " ";
        }
    } else {
        return;
    }
    
}

int main(){



    return 0;
}