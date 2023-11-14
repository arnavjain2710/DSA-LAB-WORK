#include<bits/stdc++.h>
using namespace std;


void addEdge(unordered_map<int,list<pair<int,int>>>&adj,int u,int v,int w){
	
	adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
	
}


int main(){
    int n;
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;
	
	int m;
	cout<<"Enter the number of edges"<<endl;
	cin>>m;
	cout<<"Enter the nodes between which an edge is there with their weights "<<endl;
    
	unordered_map<int,list<pair<int,int>>>adj;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(adj,u,v,w);
	}

	vector<int>key(n);
	vector<bool>mst(n);
	vector<int>parent(n);

	for(int i=0;i<n;i++){
		key[i]=INT_MAX;
		parent[i]=-1;
		mst[i]=false;
	}

	key[0]=0;
	parent[0]=-1;

	for(int i=0;i<n-1;i++){
		int mini=INT_MAX;
		int u;
		for(int v=0;v<n;v++){
			if(mst[v]==false && key[v]<mini){
				u=v;
				mini=key[v];
			}
		}
		mst[u]=true;

		for(auto it:adj[u]){
			int v=it.first;
			int w=it.second;

			if(mst[v]==false && w<key[v]){
				parent[v]=u;
				key[v]=w;
			}
		}
	}
	cout<<"The mst looks like: "<<endl;
	cout<<"vertex__weight__vertex"<<endl;
	for(int i=1;i<n;i++){
		cout<<parent[i]<<"__"<<key[i]<<"__"<<i<<endl;
	}
	
    return 0;
}