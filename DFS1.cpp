#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<list>
#include<map>
using namespace std;
class Graph
{
	map<int ,bool>	visited;
	map<int,list<int> >adj;
	public:
		void addedge(int sn,int en);
		void dfs(int n);
};
void Graph::addedge(int sn,int en)
{
	adj[sn].push_back(en);
}
void Graph::dfs(int s)
{
	visited[s]=true;
	cout << s << " ";
	list<int >:: iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++)
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
	cout << "\nEnter the edge count:";
	cin >> edge;
	Graph g;
	int sn,en;
	for(int i=0;i<edge;i++)
	{
		cin >> sn;
		cin >> en;
		g.addedge(sn,en);
	}
	int node;
	cout << "\nenter node:";
	cin >> node;
	g.dfs(node);
}
