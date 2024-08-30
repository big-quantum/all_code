#include<bits/stdc++.h>
using namespace std;

int numf[100005], nums[100005], arry[100005];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> numf[i];
        arry[numf[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    vector<int> LIS;
    LIS.push_back(-1e9);
    for(int i = 1; i <= n; i++){
        if(LIS.back() < arry[nums[i]]) LIS.push_back(arry[nums[i]]);
        else {
            int l = 0, r = LIS.size(), mid;
            while(r > l){
                mid = (l + r) >> 1;
                if(LIS[mid] < arry[nums[i]]){
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            LIS[l] = arry[nums[i]];
        }
    }
    cout <<  LIS.size() - 1 << endl;
    return 0;
}