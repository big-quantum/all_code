#include<bits/stdc++.h>
using namespace std;
int x,y,t;
struct number{
	int on;
	int nn;
}num[10005];
bool mycmp(number X,number Y){
	return X.nn < Y.nn;
}
int main() {
	cin >> x >> y;
	for(int i = x;i <= y;i++){
		t++;
		num[t].on = i;
		num[t].nn = 0;
		int tmp = i;
		while(tmp){
			num[t].nn = num[t].nn * 10 + tmp % 10;
			tmp /= 10;			
		}		
	}
	sort(num + 1,num + 1 + t,mycmp);
	
	for(int i = 1;i <= t;i++)
		cout << num[i].on << endl;
	return 0;
}
