#include<bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int> >&graph,vector<int>&visited){

    queue<int>q;
    q.push(source);
    visited[source] = 1;
    int child,current_node;

    //keep poping nodes until queue is empty
    while(!q.empty()){
        current_node = q.front();
        cout<<current_node<<" ";
        q.pop();

        //for all child nodes of current node that are not visited yet push them to queue and mark them as visited
        for(int i=0;i<graph[current_node].size();i++){
            child = graph[current_node][i];
            if(visited[child] != 1){
                q.push(child);
                visited[child] = 1;
            }
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
            bfs(i,graph,visited);
        }
    }
}
