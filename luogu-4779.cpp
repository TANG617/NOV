#include<bits/stdc++.h>
using namespace std;
const int maxn = 101010;
struct Node{
	int x, val;
	Node(int a=0, int b=0):x(a), val(b){}
	bool operator < (const Node &tx) const{
		return val > tx.val;
	} 
};

struct Edge{
	int to, val;
	Edge(int a=0, int b=0):to(a), val(b){}
};

int dis[maxn];
bool vis[maxn];
vector<Edge> v[maxn];
priority_queue<Node> que;

int main(){
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= m; i ++){
		int x, y, val;
		scanf("%d%d%d", &x, &y, &val);
		v[x].push_back(Edge(y, val));
	}
	memset(dis, 127, sizeof dis);
	dis[s] = 0;
	que.push(Node(s, 0));
	while(!que.empty()){
		Node tx = que.top(); que.pop();
		int now_pos = tx.x;
		if(vis[now_pos]) continue;
		vis[now_pos] = true;
		for(int i = v[now_pos].size() - 1; i >= 0; i --){
			int nex_pos = v[now_pos][i].to;
			if(dis[now_pos] + v[now_pos][i].val >= dis[nex_pos]) continue;
			dis[nex_pos] = dis[now_pos] + v[now_pos][i].val;
			que.push(Node(nex_pos, dis[nex_pos]));
		}
	}
	for(int i = 1; i <= n; i ++)
		printf("%d ", dis[i]);
} 
