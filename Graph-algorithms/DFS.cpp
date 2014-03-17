#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

void add_edge(vector<int>* adj,int i,int j){
        adj[i].push_back(j);
}

void _DFS(vector<int>* adj,int v,bool *visited){
    visited[v]=true;
    cout<<v<<" ";
    for(int i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            _DFS(adj,adj[v][i],visited);
        }
    }

}

void DFS(vector<int>* adj,int V,int source=0)
{
    bool visited[V];
    memset(visited,false,sizeof(bool)*V);
    _DFS(adj,source,visited);
}

int main(){
	int n=4;
	vector<int> adj[n];
	add_edge(adj,0,1);
	add_edge(adj,0,2);
	add_edge(adj,1,2);
	add_edge(adj,2,0);
	add_edge(adj,2,3);
	add_edge(adj,3,3);
	DFS(adj,n,2);
	return 0;
}
