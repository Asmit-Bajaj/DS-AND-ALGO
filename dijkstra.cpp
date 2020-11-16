#include<bits/stdc++.h>
using namespace std;

/*0 1 6
1 2 5
0 3 1
1 3 2
2 4 2
3 4 1
4 2 5*/

int dijkstra(int source,vector<pair<int,int> >graph[],int n){
    int visited[n] = {0};
    int distance[n];

    distance[0] = 0;

    //setting all vertices weight as infinity
    for(int i=1;i<n;i++){
        distance[i] = INT_MAX;
    }

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pair<int,int> p;

    pq.push(make_pair(distance[source],source));


    while(!pq.empty()){
        p = pq.top();
        int current  = p.second;

        cout<<current<<" :c ";
        pq.pop();

        if(visited[current] == 1){
            continue;
        }

        cout<<endl;
        visited[current] = 1;
        for(int i=0;i<graph[current].size();i++){
                if(visited[graph[current][i].second] == 0){
                    if(distance[graph[current][i].second] > distance[current]+graph[current][i].first){
                         distance[graph[current][i].second] = distance[current]+graph[current][i].first;
                         //cout<<distance[graph[current][i].second]<<endl
                         pq.push(make_pair(distance[graph[current][i].second],graph[current][i].second));
                    }
                }
        }
    }
    cout<<endl;

    for(int i=1;i<n;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int vertices;
    int edges;
    int u,v,ew;

    cout<<"Enter the number of vertices and edges(along with weight): ";
    cin>>vertices>>edges;

    vector<pair<int,int> >graph[vertices];

    cout<<"Enter the edges : ";
    for(int i=0;i<edges;i++){
        cin>>u>>v>>ew;
        graph[u].push_back(make_pair(ew,v));
        //undirected graph
        graph[v].push_back(make_pair(ew,u));
    }

    cout<<"Shortest path is : ";
    dijkstra(0,graph,vertices);
    return 0;
}
