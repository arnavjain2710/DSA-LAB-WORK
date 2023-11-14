#include <bits/stdc++.h>
using namespace std;

/*
Q3.

                54
             /      \
            66      45
           / \     / | \
          87 63   39 56 61
                         \
                          7 
                          
Perform a breadth-first search (BFS) traversal starting from the root node (54). Breadth-First Search (BFS) is
a graph traversal algorithm that explores all neighbor nodes at the current depth level before moving to the next
depth level. For above graph it will be : 54 66 45 87 63 39 56 61 7.

The algorithm for BFS traversal is given below:
Input: s as the source node
BFS (G, s)
let Q be queue.
Q.enqueue( s )
mark s as visited
while ( Q is not empty)
v = Q.dequeue( )
for all neighbors w of v in Graph G
if w is not visited
Q.enqueue( w )
mark w as visited

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
//run bfs algo on root and push node value in bfs vector
void bfs(vector<int>g[],vector<bool>&vis,int root){
	queue<int>q;
	q.push(root);
	while(!q.empty()){
		int x=q.front();
		//bfsvec.push_back(x);
		cout<<x<<" ";
		vis[x]=1;
		q.pop();
		for(int z:g[x])if(!vis[z])q.push(z);
	}
	
}
// print vector
/*void print(vector<int>a){
	for(auto x:a)cout<<x<<" ";
	}
*/
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
	
	//visited boolean vector
	vector<bool>vis(100,0);

	bfs(g,vis,54);
	//print ans
	//print(ans);
	
	
	
return 0;
}
