#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int MAXN=100005;
int n,m,cnt;//cnt是答案数组的下标
int indeg[MAXN],ans[MAXN];
vector <int> edge[MAXN];//vector建图就是方便！
 
void input(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[y].push_back(x);//反向建图
        indeg[x]++;
    }
}

void topo_sort(void)
{
    priority_queue <int> q;//大根堆，每次取最大值
    for(int i=1;i<=n;i++)
      if(!indeg[i])
       q.push(i);//初始化一下队列
    while(!q.empty())
    {
        const int tmp=q.top();//不要加引用符&！！！
        q.pop();
        ans[++cnt]=tmp;
        for(vector<int>::iterator it=edge[tmp].begin();it!=edge[tmp].end();it++)//遍历边
        {
            indeg[*it]--;//拓扑排序
            if(!indeg[*it])
             q.push(*it);
         } 
    }
}

void output(void)
{
    if(cnt<n)//答案数组长度不足，有闭环，不符题意
    {
        puts("Impossible!");
        return;
    }
    for(int i=n;i>=1;i--)//记得倒序输出QVQ
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
        clear();//清空很重要
        input();
        topo_sort();
        output();
    }
    return 0;
}
