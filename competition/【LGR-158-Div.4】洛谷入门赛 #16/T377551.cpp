#include<bits/stdc++.h>
using namespace std;

long long t; 
float x0, a;

//ceil() 向上取整 
//floor() 向下取整 

int main() {
	cin >> t;
	
	for(int i = 1;i <= t ;i++){
		cin >> x0 >> a;
		
		x0 = x0 * 1.0;
		a = a * 1.0;
		
		float tmp = floor((x0 + a) / a);
		cout << x0 << " ";
		
		while(tmp != x0){
			tmp = floor((x0 + a) / a);
			x0 = tmp * 1.0;
			cout << x0 << " ";
		}
		cout << endl;
		
	}
	
	return 0;
}
