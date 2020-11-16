#include<bits/stdc++.h>
using namespace std;

//finding parent of the current node
//(4,3)->(3,2)->(2,1)->(1,1) hence parent of 4 is 1 also setting parent of 4 as 1 so that
int find_parent(vector<int>&p,int node){
    int curr = node;
    while(p[node] != node){
        node = p[node];
    }

    //dynamic programming so that we will not traverse the full array every time
    return p[curr] = node;
}

//taking union of given nodes setting common parent
bool union_(int x,int y,vector<int>&p){
    int fpx = find_parent(p,x);
    int fpy = find_parent(p,y);

    //if same parent then no need to take union as cycle exist
    if(fpx == fpy){
        return false;
    }

    p[fpy] = fpx;
    return true;
}

/*input :
6
8
1 3 2
1 2 1
3 2 3
3 4 4
3 6 6
3 5 5
4 5 7
6 5 8*/
int main(){
    int nodes;
    cin>>nodes;

    int edges,x,y,wt;
    cin>>edges;
    vector<int>p(nodes+1);
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

    //everyone is parent of oneself
    for(int i=1;i<=nodes;i++){
        p[i] = i;
    }

    for(int i=0;i<edges;i++){
        cin>>x>>y>>wt;
        pq.push(make_pair(wt,make_pair(x,y)));
    }

    pair<int,pair<int,int> >pr;

    bool flag;
    int min_cost = 0;

    while(!pq.empty()){
        pr = pq.top();
        pq.pop();
        flag = union_(pr.second.first,pr.second.second,p);

        if(flag){
            min_cost +=pr.first;
        }
    }
    cout<<min_cost<<endl;
    return 0;
}
