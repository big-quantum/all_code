#include<bits/stdc++.h>
using namespace std;
int T,M,w[105],v[105],ans,num[105];

int main() {
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	cin >> T >> M;
	for(int i = 1;i <= M;i++)
		cin >> w[i] >> v[i];
	while(num[0] == 0){
		int weight = 0,s = 0;
		for(int i = 1;i <= M;i++){
			weight = weight + num[i] * w[i];
			s = s + num[i] * v[i];
		}
		if (weight <= T)
			ans = max(ans,s);	
		int j = M;
		while(num[j] == 1)
			j--;
		num[j] = 1;
		for(int i = j + 1;i <= M;i++)
			num[i] = 0;	
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
