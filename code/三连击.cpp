#include<bits/stdc++.h>
using namespace std;
int used[10];
int main(){
	for(int i = 100;i <= 333;i++){
		for(int j = 0;j < 10;j++)
			used[j] = 0;
		for(int j = 1;j <= 3;j++){
			used[j * i % 10] = 1;
			used[i * j / 10 % 10] = 1;
			used[i * j / 100] = 1;
		}
		int s = 0;
		for(int j = 1;j <= 9;j++)
			s += used[j];
		if (s == 9)
			cout << i << " " << 2 * i << " " << 3 * i << endl;
	}
	return 0;
}
