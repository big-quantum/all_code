#include<bits/stdc++.h>
using namespace std;
struct student{
	int c,m,e,sum,id;	
};
student s[305];
int n;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i].c >> s[i].m >> s[i].e;
		s[i].id = i;
		s[i].sum = s[i].c + s[i].m + s[i].e;	
	}
	for(int i = 1;i < n;i++)
		for(int j = i + 1;j <= n;j++)
			if (s[i].sum < s[j].sum || (s[i].sum == s[j].sum && s[i].c < s[j].c) || (s[i].sum == s[j].sum && s[i].c == s[j].c && s[i].id > s[j].id))
				swap(s[i],s[j]);
	for(int i = 1;i <= 5;i++)	
		cout << s[i].id << " " << s[i].sum << endl;
	return 0;
}
