#include<bits/stdc++.h>
using namespace std;
int n,q[1000005] = {2,3,5,7},f,r;
int num[4] = {1,3,7,9};
bool check(int x){
	if (x < 2)
		return false;
	for(int i = 2;i <= sqrt(x);i++)
		if (x % i == 0)
			return false;
	return true;	
}
int main(){
	cin >> n;
	f = 0;//头指针 
	r = 3;//尾指针
	int maxnum = pow(10,n) - 1;
	int minnum = pow(10,n - 1);
	while(f <= r){
		if (q[f] >= minnum && q[f] <= maxnum)//队头元素是n位数，直接输出，不再扩展 
			cout << q[f] << endl;
		else 
			for(int i = 0;i < 4;i++)
			   if (check(q[f] * 10 + num[i])){//构造新的数加入队列中 
				  r++;
				  q[r] = q[f] * 10 + num[i];
			   }					
		f++;
	} 
	return 0;	
}
 
