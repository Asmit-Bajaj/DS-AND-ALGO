#include<bits/stdc++.h>
using namespace std;

void store_graph_matrix(int n,int e){
    int graph[n][n];

    cout<<"Enter the edges : ";
    int x,y;

    for(int i=0;i<e;i++){
        cin>>x>>y;
        graph[x][y] = 1;

        //for undirected graph
        //graph[y][x] = 1;
    }

    cout<<"Graph in matrix form : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void store_graph_vector(int n,int e){
    vector<vector<int> >v(n);

    cout<<"Enter the edges : ";
    int x,y;

    for(int i=0;i<e;i++){
        cin>>x>>y;
        v[x].push_back(y);

        //for undirected graph
        //v[y].push_back(x);
    }

    cout<<"Graph in vector form : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int nodes,edges;
    cout<<"Enter the number of nodes : ";
    cin>>nodes;

    cout<<"Enter the number of edges : ";
    cin>>edges;

    store_graph_vector(nodes,edges);
}
