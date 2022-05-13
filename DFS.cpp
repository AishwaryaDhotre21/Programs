#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<list>
#include<map>
using namespace std;
class Graph
{
	map<int ,bool>visited;
	map<int,list<int> >adj;
	public:
		void addedge(int sn,int en);
		void dfs(int n);
	
};
void Graph::addedge(int sn,int en)
{
	adj[sn].push_back(en);
}
void Graph::dfs(int node)
{
	visited[node]=true;
	cout << node <<  " ";
	list<int> ::iterator i;
	for(i=adj[node].begin();i!=adj[node].end();i++)
	{
		if(!visited[*i])
		{
			dfs(*i);
		}
	}
}
int main()
{
	int edge;
	cout << "\nEnter the count of edge:";
	cin >> edge;
	int sn,en;
	Graph g;
	for(int i=0;i<edge;i++)
	{
		cin >> sn;
		cin >> en;
		g.addedge(sn,en);
	}
	int node;
	cout << "\nEnter the node to find dfs:\n";
	cin >> node;
	g.dfs(node);
	return 0;
}
