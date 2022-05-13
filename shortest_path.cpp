#include<iostream>
//#include<stdc++/bits>
#include<list>
#include<set>
#include<vector>
using namespace std;
# define inf 10000
class Graph{
	public:
		int vertex;
		list <pair<int ,int> >*adj;
		Graph(int v);
		void addedge(int sn,int en,int wt);
		void fun(int v);
};
Graph::Graph(int v)
{
	vertex=v;
	adj=new list<pair<int,int> >[v];
}
void Graph::addedge(int sn ,int en,int wt)
{
	adj[sn].push_back(make_pair(en,wt));
	adj[en].push_back(make_pair(sn,wt));
}
void Graph::fun(int src)
{
	set<pair<int,int> > setds;
	vector<int> dist(vertex,inf);
	setds.insert(make_pair(0,src));
	dist[src]=0;
	while(!setds.empty())
	{
		pair<int,int> tmp=*(setds.begin());
		setds.erase(setds.begin());
		int u=tmp.second;
		list<pair<int,int> >::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			int v=(*i).first;
			int wt=(*i).second;
			if(dist[v]>dist[u]+wt)
			{
				if(dist[v]!=inf)
				{
					setds.erase(setds.find(make_pair(dist[v],v)));
				}
				dist[v]=dist[u]+wt;
				setds.insert(make_pair(dist[v],v));
			}
		}
	}
	cout << "\nShortest path to all nodes from source " << src << ":\n";
	for(int i=0;i<vertex;i++)
	{
		cout << i << " == " << dist[i];
		cout << "\n";
	}
}
int main()
{
	int vertex;
	cout << "\nEnter the number of vertex:";
	cin >> vertex;
	Graph g(vertex);
	cout << "\n Enter the number of edges:\n";
	int edge;
	cin >> edge;
	int sn,en,wt;
	for(int i=0;i<edge;i++)
	{
		cout << "\nEnter the start vertex:";
		cin >> sn;
		cout << "\nEnter the end vertex:";
		cin >> en;
		cout << "\nEnter the weight of this edge from point " << sn << " to " << en << " :";
		cin >> wt;
		g.addedge( sn,en, wt);
	}
	int v;
	cout << "\Enter the node whose shortest path do u want:";
	cin >> v;
	g.fun(v);
}
