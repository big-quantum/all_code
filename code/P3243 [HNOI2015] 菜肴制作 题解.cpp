#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int MAXN=100005;
int n,m,cnt;//cnt�Ǵ�������±�
int indeg[MAXN],ans[MAXN];
vector <int> edge[MAXN];//vector��ͼ���Ƿ��㣡
 
void input(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[y].push_back(x);//����ͼ
        indeg[x]++;
    }
}

void topo_sort(void)
{
    priority_queue <int> q;//����ѣ�ÿ��ȡ���ֵ
    for(int i=1;i<=n;i++)
      if(!indeg[i])
       q.push(i);//��ʼ��һ�¶���
    while(!q.empty())
    {
        const int tmp=q.top();//��Ҫ�����÷�&������
        q.pop();
        ans[++cnt]=tmp;
        for(vector<int>::iterator it=edge[tmp].begin();it!=edge[tmp].end();it++)//������
        {
            indeg[*it]--;//��������
            if(!indeg[*it])
             q.push(*it);
         } 
    }
}

void output(void)
{
    if(cnt<n)//�����鳤�Ȳ��㣬�бջ�����������
    {
        puts("Impossible!");
        return;
    }
    for(int i=n;i>=1;i--)//�ǵõ������QVQ
     cout<<ans[i]<<' ';
    cout<<endl;
}

void clear(void)
{
    cnt=0;
    memset(ans,0,sizeof(ans));
    memset(indeg,0,sizeof(indeg));
    for(int i=1;i<=n;i++)
     edge[i].clear();
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        clear();//��պ���Ҫ
        input();
        topo_sort();
        output();
    }
    return 0;
}
