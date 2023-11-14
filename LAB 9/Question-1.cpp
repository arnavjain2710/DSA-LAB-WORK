#include <bits/stdc++.h>
using namespace std;
void addVertex(vector<int> &v , int data)
{
    v.push_back(data);
}
void print(vector<int> v)
{
    cout<<"The vertexes this vertex is attached to are:"<<endl;
    if(v.size()>0)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    else
    {
        cout<<"It is attached to no vertex";
    }
    cout<<endl;
}
int main()
{
    vector<int> vertexs;
    vector<vector<int>> edges(9);
    vertexs.push_back(54);
    vertexs.push_back(66);
    vertexs.push_back(45);
    vertexs.push_back(87);
    vertexs.push_back(63);
    vertexs.push_back(39);
    vertexs.push_back(56);
    vertexs.push_back(61);
    vertexs.push_back(7);
    addVertex(edges[0], 66);
    addVertex(edges[0] , 45);
    addVertex(edges[1], 54);
    addVertex(edges[1] , 87);
    addVertex(edges[1] , 63);
    addVertex(edges[2], 54);
    addVertex(edges[2] , 39);
    addVertex(edges[2] , 56);
    addVertex(edges[2] , 61);
    addVertex(edges[3], 66);
    addVertex(edges[4], 66);
    addVertex(edges[5], 45);
    addVertex(edges[6], 45);
    addVertex(edges[7], 45);
    addVertex(edges[7] , 7);
    addVertex(edges[8], 61);
    print(edges[2]);
    return 0;
}