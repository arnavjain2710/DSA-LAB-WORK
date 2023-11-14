#include<bits/stdc++.h>
using namespace std;


unordered_map<char,list<char>>adj;

void addEdge(char u,char v,bool direction){
	//direction=0--undirected
	//direction=1--directed graph
	//creating edge from u to v
	adj[u].push_back(v);
		
	if(direction==0){
	    adj[v].push_back(u);
	}
}


vector<char>DFS(int n,int m,char src,unordered_map<char,list<char>>&adj,unordered_map<int ,bool>&vis){
    vector<char>ans;
    stack <int>s;
    s.push(src);
    
    while (!s.empty()){
        char front = s.top();
        ans.push_back(front);
        s.pop();
        
        for(auto i:adj[front]){
            if(!vis[i]){
                s.push(i);
                vis[i]=1;
            }
        }
    }
    return ans;
    
}
	
int main(){
    int n;
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;
	
	int m;
	cout<<"Enter the number of edges"<<endl;
	cin>>m;
	

	
	cout<<"Enter the nodes between which an edge is there"<<endl;
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v,0);
	}
	
	unordered_map<int ,bool>vis;
	vector<char>op = DFS(n,m,'A',adj,vis);
	
	for(auto i=0;i<op.size();i++){
	    cout<<op[i]<<" ";
	}cout<<endl;

    return 0;
}