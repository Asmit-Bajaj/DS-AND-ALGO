#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<vector<int> >&graph,vector<int>&visited){

    visited[source] = 1;
    //mark current as visited
    cout<<source<<" ";

    //for all child nodes of current node that are not visited yet call dfs for them
    for(int i=0;i<graph[source].size();i++){
        int child = graph[source][i];
        if(visited[child] != 1){
            dfs(child,graph,visited);
        }
    }

}

int main(){

    int nodes,edges;
    cout<<"Enter the number of nodes : ";
    cin>>nodes;

    cout<<"Enter the number of edges : ";
    cin>>edges;

    vector<vector<int> >graph(nodes);

    cout<<"Enter the edges : ";
    int x,y;

    for(int i=0;i<edges;i++){
        cin>>x>>y;
        graph[x].push_back(y);

        //for undirected graph
        //v[y].push_back(x);
    }

    vector<int>visited(nodes);

    for(int i=0;i<nodes;i++){
        if(visited[i] != 1){
            dfs(i,graph,visited);
        }
    }
}
