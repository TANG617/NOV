// 贝尔曼-福特算法的队列优化形式
// Bellman-Ford using queue optimization
#include<bits/stdc++.h>
using namespace std;
const long long inf=2147483647;//2^31-1  ->max number of 32Bit
const int maxn=10005;
const int maxm=500005;
int n,m,s,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
struct Edge{
    int next,distance,toward;
}edge[maxm];

void addedge(int from,int to,int dis) //邻接表建图
{ 
  edge[++num_edge].next=head[from]; //链式存储下一条出边
  edge[num_edge].toward=to; //当前节点编号
  edge[num_edge].distance=dis; //本条边的距离
  head[from]=num_edge; //记录下一次的出边情况
}
void spfa()//spfa_main
{
    queue<int> q;//stl队列
    for(int i=1;i<=n;i++)//初始化
    {
        dis[i]=inf;
        vis[i]=0;//访问情况
    }
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i;i=edge[i].next)
        {
            int v=edge[i].toward;
            if(dis[v]>dis[u]+edge[i].distance)
            {
                dis[v]=dis[u]+edge[i].distance;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int f,g,w;
        cin>>f>>g>>w;
        addedge(f,g,w);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    spfa();
    for(int i=1;i<=n;i++)
    {
        if(s==i)
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<dis[i]<<" ";
        }
    }
}