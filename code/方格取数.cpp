#include<bits/stdc++.h>
using namespace std;
int f[12][12][12][12],a[12][12],n,x,y,num;
int main() {
    cin>>n>>x>>y>>num;
    while(x!=0||y!=0||num!=0){
        a[x][y]=num;
        cin>>x>>y>>num;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                        if(i==k&&j==l)f[i][j][k][l]-=a[i][j];//���� �������˶���һ��λ��ʱ������һ��,��˼�ȥ 
                    }
                }
            }
        }
    cout<<f[n][n][n][n]<<endl;
    return 0;
}
/*
f[i][j]�ǵ�һ���˵�λ��,���� f[i-1][j][][],���� f[][][i][j-1]; 
f[k][l]�ǵڶ����˵�λ��,���� f[k-1][l][][],���� f[][][k][l-1];
�ɴ���ϳ��������߷�ʽ f[i-1][j][k-1][l],
					   f[i-1][j][k][l-1],
					   f[i][j-1][k-1][l],
					   f[i][j-1][k][l-1].
�ɴ˵ó�״̬ת�Ʒ���:f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];(��ǰλ�õ�����) 
*/
