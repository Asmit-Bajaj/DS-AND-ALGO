#include<bits/stdc++.h>
using namespace std;

bool valid(int x,int y,int n,int m){
    // cout<<x<<y<<endl;
    if(x < 1 || x > n || y<1 || y>m){
        // cout<<"false"<<endl;
        return false;
    }
    else{
        // cout<<"true"<<endl;
        return true;
    }
}

int main() {
	int test;
	cin>>test;

	int n,i,j;
	while(test--){
	    cin>>n;

	    int visited[n+1][n+1];
	    int dist[n+1][n+1];
	    int src_x,src_y;
	    int dest_x,dest_y;

	    for(i=1;i<=n;i++){
	        for(j=1;j<=n;j++){
	            visited[i][j] = 0;
	            dist[i][j] = 0;
	        }
	    }

	    cin>>src_x>>src_y;
	    cin>>dest_x>>dest_y;

	    queue<pair<int,int> >q;
        q.push(make_pair(src_x,src_y));
        visited[src_x][src_y] = 1;

        int current_node_x,current_node_y;


    //keep poping nodes until queue is empty
    while(!q.empty()){
        cout<<"hii";
        current_node_x = q.front().first;
        current_node_y = q.front().second;

        if(current_node_x == dest_x && current_node_y == dest_y){
            break;
        }

        q.pop();

        //for all child nodes of current node that are not visited yet push them to queue and mark them as visited
        if(valid(current_node_x-2,current_node_y-1,n,n) &&
            visited[current_node_x-2][current_node_y-1] == 0
        ){
            visited[current_node_x-2][current_node_y-1] = 1;
            q.push(make_pair(current_node_x-2,current_node_y-1));
            dist[current_node_x-2][current_node_y-1] = dist[current_node_x-2][current_node_y-1]+1;
        }


        if(valid(current_node_x-2,current_node_y+1,n,n) &&
            visited[current_node_x-2][current_node_y+1] == 0
        ){

            visited[current_node_x-2][current_node_y+1] = 1;
            q.push(make_pair(current_node_x-2,current_node_y+1));
            dist[current_node_x-2][current_node_y+1] = dist[current_node_x][current_node_y]+1;
        }

        if(valid(current_node_x+2,current_node_y-1,n,n) &&
            visited[current_node_x+2][current_node_y-1] == 0
        ){

            visited[current_node_x+2][current_node_y-1] = 1;
            q.push(make_pair(current_node_x+2,current_node_y-1));
            dist[current_node_x+2][current_node_y-1] = dist[current_node_x][current_node_y]+1;

        }

        if(valid(current_node_x+2,current_node_y+1,n,n) &&
            visited[current_node_x+2][current_node_y+1] == 0
        ){

            visited[current_node_x+2][current_node_y+1] = 1;
            q.push(make_pair(current_node_x+2,current_node_y+1));
            dist[current_node_x+2][current_node_y+1] = dist[current_node_x][current_node_y]+1;
        }

        if(valid(current_node_x-1,current_node_y-2,n,n) &&
            visited[current_node_x-1][current_node_y-2] == 0
        ){

            visited[current_node_x-1][current_node_y-2] = 1;
            q.push(make_pair(current_node_x-1,current_node_y-2));
            dist[current_node_x-1][current_node_y-2] = dist[current_node_x][current_node_y]+1;
        }

        if(valid(current_node_x-1,current_node_y+2,n,n) &&
            visited[current_node_x-1][current_node_y+2] == 0
        ){

            visited[current_node_x-1][current_node_y+2] = 1;
            q.push(make_pair(current_node_x-1,current_node_y+2));
            dist[current_node_x-1][current_node_y+2] = dist[current_node_x][current_node_y]+1;
        }

        if(valid(current_node_x+1,current_node_y-2,n,n) &&
            visited[current_node_x+1][current_node_y-2] == 0
        ){

            visited[current_node_x+1][current_node_y-2] = 1;
            q.push(make_pair(current_node_x+1,current_node_y-2));
            dist[current_node_x+1][current_node_y-2] = dist[current_node_x][current_node_y]+1;
        }

        if(valid(current_node_x+1,current_node_y+2,n,n) &&
            visited[current_node_x+1][current_node_y+2] == 0
        ){

            visited[current_node_x+1][current_node_y+2] = 1;
            q.push(make_pair(current_node_x+1,current_node_y+2));
            dist[current_node_x+1][current_node_y+2] = dist[current_node_x][current_node_y]+1;
        }

    }

    cout<<dist[dest_x][dest_y]<<"\n";
}
	return 0;
}
