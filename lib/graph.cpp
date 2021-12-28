#include <bits/stdc++.h>
using namespace std;
#define INF 4000


//===================== D I J K S T R A ===============================
int n,m;
vector<pair<int,long long>>adj[INF];
void dijkstra(int node)
{
	long long distance[INF];
	bool processed[INF];
	for(int i=1;i<=n;i++)
	{
		distance[i]=INT_MAX;
		processed[i]=false;
	}
	distance[node]=0LL;
	priority_queue<pair<long long,int>>pq;
	pq.push({0LL,node});
	while(!pq.empty())
	{
		int a=pq.top().second;
		pq.pop();
		if(processed[a]) continue;
		processed[a]=true;
		for(auto u:adj[a])
		{
			int b=u.first;
			long long w=u.second;
			if(distance[a]+w<distance[b])
			{
				distance[b]=distance[a]+w;
				pq.push({-distance[b],b});
			}
		}
	}
}

//===================== B F S =========================================
vector<int>adj[INF];

void bfs(int source)
{
	int level[INF]={0};
	bool vis[INF]={false};
	queue<int>q;
	q.push(source);
	level[source]=0;
	vis[source]=true;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(auto next:adj[p])
		{
			if(vis[next]==false)
			{
				level[next]=level[p]+1;
				q.push(next);
				vis[next]=true;
			}
		}
	}
}

//================== BELLMEN - FORD ===================================

void bford()
{
	vector<tuple<int,int,int>>adj;
	long long distance[LIM];
    for(int i=1;i<=n;i++) distance[i]=LLONG_MIN+1000000055LL;
    distance[1]=0LL;
	
	for(int i=1;i<=n-1;i++)
    {
        for(int k=0;k<m;k++)
        {
            int aa,bb,cc;
            tie(aa,bb,cc)=adj[k];
            distance[bb]=max(distance[bb],distance[aa]+cc);
        }
    }
}

//==== BELLMEN FORD TO FINDING NEGATIVE CYCLE ==========================
// idea is, initially all the node's distance will be 0, if there is neg
//cycle, then in the N'th iteration, it will show up, and from that,  we
//will pick a node which is updated. After that, we'll first go to  that
//node's top parent, because, current node could be a node, which in not
//in the cycle, but can be recheable from any negative cycle, in that ca
//-se, that will provide negative cost, although it is out of the cycle. 

void bford()
{
	long long distance[LIM];
	int parent[LIM];
	memset(parent,-1,sizeof(parent));
    bool cycle=false;
    int start;
	for(int i=1;i<=n;i++) distance[i]=0LL;
	
	for(int i=1;i<=n;i++)
    {
        for(int k=0;k<m;k++)
        {
            int aa,bb,cc;
            tie(aa,bb,cc)=adj[k];
            if(distance[bb]>distance[aa]+cc)
            {
            	distance[bb]=max(0LL+INT_MIN,distance[aa]+cc);
            	parent[bb]=aa;
            	if(i==n) cycle=true,start=bb;
            }
        }
    }
    if(!cycle)
    {
    	cout << "NO" << "\n";
    }else
    {
    	cout << "YES" << "\n";
    	for(int i=0;i<n;i++)
    	{
    		start=parent[start];
    	}
    	vector<int>serial;
    	for(int i=start;;)
    	{
			serial.push_back(i);
			i=parent[i];
			if(i==start) break;
    	}
    	for(int i=serial.size()-1;i>=0;i--)
    	{
    		cout << serial[i] << " ";
    	}
    	cout << serial[serial.size()-1] << "\n";
    }
}

//================== TOPOLOGICAL - SORT ================================

bool cycle=false;
vector<int>run;
vector<int>serial;
int color[LIM];

void topsort(int node)
{
	color[node]=gray;
	for(auto next:adj[node])
	{
		if(color[next]==white)
		{
			topsort(next);
		}else
		if(color[next]==gray)
		{
			cycle=true;
		}
	}
	run.push_back(node);
	color[node]=black;
}

//===================== MST - KRUSKAL ==================================

vector<tuple<int,int,int>>adj;
int id[LIM];

void init()
{
	for(int i=0;i<LIM;i++) id[i]=i;
}

int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

long long kruskal()
{
	init();
	sort(adj.begin(),adj.end());
	long long cost=0LL;
	for(int i=0;i<adj.size();i++)
	{
		int x,y,c;
		tie(c,x,y)=adj[i];
		if(root(x)!=root(y))
		{
			cost+=c;
			union1(x,y);
		}
	}
	return cost;
}

//======================= D S U =========================================

int id[LIM];
int sz[LIM];

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		id[i]=i;
		sz[i]=1;
	}
}

int root(int v)
{
	if(v==id[v]) return v;
    return id[v]=root(id[v]);
}

void union1(int a,int b) 
{
    a=root(a);
    b=root(b);
    if(a!=b) 
    {
        if(sz[a]<sz[b]) swap(a,b);
        id[b]=a;
        sz[a]+=sz[b];
    }
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
}
