#include<bits/stdc++.h>
using namespace std;
struct edge{
    int x;
    int y;
    int z;
};


int main(){
    int v,e;
    int test;
    cin>>test;


    while(test--){
        cin>>v>>e;
        int dist[v+1];

        for(int i=0;i<v;i++){
            dist[i] = INT_MAX;
        }

        //cout<<dist[1]<<endl<<endl;
        struct edge ed[e];
        dist[0] = 0;

        for(int i=0;i<e;i++){
            cin>>ed[i].x>>ed[i].y>>ed[i].z;
        }

        for(int i=0;i<v-1;i++){
            for(int j=0;j<e;j++){
                int u = ed[j].x;
                int v = ed[j].y;
                int wt = ed[j].z;

                if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                   // cout<<dist[v]<<endl;
                }
            }
        }

        bool flag =false;
        for(int j=0;j<e;j++){
               int u = ed[j].x;
                int v = ed[j].y;
                int wt = ed[j].z;

                if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    flag = true;
                    break;
                    //cout<<dist[v]<<endl;
                }
        }

        /*for(int i=0;i<v;i++){
            cout<<dist[i]<<" "<<endl;
        }*/

        //cout<<endl;

        if(flag){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }


    }
    return 0;
}
