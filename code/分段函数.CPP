#include<bits/stdc++.h>
using namespace std;
double x,y;
int main(){
	cin >> x;
	if (x >= 0 && x < 5) y = -x + 2.5;
	if (x >= 5 && x < 10) y = 2 - 1.5 * (x - 3) * (x - 3);
	if (x >= 10 && x < 20) y = x / 2 - 1.5;
	printf("%.3lf\n",y);
	return 0;	
}
