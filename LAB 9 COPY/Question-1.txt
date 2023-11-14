#include <bits/stdc++.h>
using namespace std;

/*
Q1.
Create a graph representing the following tree structure:

                54
             /      \
            66      45
           / \     / | \
          87 63   39 56 61
                         \
                          7 
*/

void addEdge(vector<int>g[],int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}

void print1(vector<int>g[]){
	for(int i=0;i<100;i++){
		if(g[i].size()>0){
			cout<<i<<" - ";
			for(int x:g[i]){cout<<x<<" ";}
			cout<<endl;
			}
	}
}

int main(){
	vector<int>g[100];
	
	//form graph edges
	
	addEdge(g,54,66);
	addEdge(g,54,45);
	addEdge(g,66,87);
	addEdge(g,66,63);
	addEdge(g,45,39);
	addEdge(g,45,56);
	addEdge(g,45,61);
	addEdge(g,61,7);
	
	print1(g);
	
	
	
	
return 0;
}
