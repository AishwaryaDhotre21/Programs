#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<list>
using namespace std;
class Graph
{
		int vertex;
		list<int> *adj;
	public:
		Graph(int v);
		void addEdge(int s,int e);
		void BFS(int s);
};
Graph::Graph(int v)
{
	vertex=v;
	adj=new list<int>[v];
}
void Graph::addEdge(int s,int e)
{
	adj[s].push_back(e);
}
void Graph::BFS(int s)
{
	bool *visited=new bool[vertex];
	for(int i=0;i<vertex;i++)
	{
		visited[i]=false;
	}
	visited[s]=true;
	list<int> q1;
	q1.push_back(s);
	list<int>::iterator i;
	while(!q1.empty())
	{
		int node;
		node=q1.front();
		q1.pop_front();
		cout << node << " => ";
		for(i=adj[node].begin();i!=adj[node].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q1.push_back(*i);
			}
			
		}
	}
}
	
int main()
{	
	int vertex;
	cout << "\nEnter how many vertex do u want ?";
	cin >> vertex;
	Graph g(vertex);
	cout << "\nEnter how many edges do u want ?";
	int edge;
	cin >> edge;
	int sn,en;
	for(int i=0;i<edge;i++)
	{
		cout << "\nEnter the start node:";
		cin >> sn;
		cout << "\nEnter the end node:";
		cin >> en;
		g.addEdge(sn,en);
	}
	int node;
	cout << "\nEnter the node whose whose BFS do u want:\n";
	cin >> node;
	g.BFS(node);
	return 0;
}
