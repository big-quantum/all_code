#include <bits/stdc++.h>
using namespace std;
int a;
double yuan;
int main(){
    cin>>a;
    if(a<=150) yuan=0.4463*a;
    else if(a>=151&&a<=400) yuan=0.4463*150+(a-150)*0.4663;
    else yuan=0.4463*150+0.4663*250+(a-400)*0.5663;
    cout<<fixed<<setprecision(1)<<yuan<<endl;
    return 0;
}
