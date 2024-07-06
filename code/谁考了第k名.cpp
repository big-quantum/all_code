#include<bits/stdc++.h>
using namespace std;
#define Maxn 105
struct stu{
	int id;//Ñ§ºÅ 
	float score;//³É¼¨ 
};
stu s[Maxn];
int n,k;
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> s[i].id >> s[i].score;
	for(int i = 1;i < n;i++)
		for(int j = i + 1;j <= n;j++)
			if (s[i].score < s[j].score)
				swap(s[i],s[j]);
	printf("%d %g\n",s[k].id,s[k].score);
	return 0;	
}
