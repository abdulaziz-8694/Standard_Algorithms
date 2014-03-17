#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

void add_edge(vector<int>* adj,int i,int j){ 
        adj[i].push_back(j);
}

void BFS(vector<int>* adj,int n,int start=0){
	bool visited[n];
	memset(visited,false,sizeof(bool)*n);
	list<int> q;
	visited[start]=true;
	q.push_back(start);
	while(!q.empty()){
		int v = q.front();
		cout<<v<<" ";
		q.pop_front();
		for(int i=0;i<adj[v].size();++i){
				if(!visited[adj[v][i]]){
					visited[adj[v][i]]=true;
					q.push_back(adj[v][i]);
				}
		}
	}
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
	BFS(adj,n,2);
	return 0;
}
