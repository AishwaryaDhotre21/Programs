#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<list>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int ver);
		void addEdge(int sn,int en);
		void bfs(int s);
};
Graph::Graph(int ver)
{
	v=ver;
	adj=new list<int>[ver];
}
void Graph::addEdge(int sn,int en)
{
	adj[sn].push_back(en);
}
void Graph::bfs(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	visited[s]=true;
	list<int>q;
	q.push_back(s);
	list<int>::iterator i;
	while(!q.empty())
	{
		int n;
		n=q.front();
		q.pop_front();
		cout << n << " ";
		for(i=adj[n].begin();i!=adj[n].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push_back(*i);
			}
		}
		
	}
}
int main()
{
	int v;
	int edge;
	cout << "\nVertex count:";
	cin >> v;
	cout << "\nEdge count:";
	cin >> edge;
	Graph g(v);
	int sn,en;
	for(int i=0;i<edge;i++)
	{
		cin >> sn;
		cin >> en;
		g.addEdge(sn,en);
	}
	int node;
	cout << "\nEnter node num:";
	cin >>  node;
	g.bfs(node);
	return 0;
}
