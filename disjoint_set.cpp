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
void union_(int x,int y,vector<int>&p){
    int fpx = find_parent(p,x);
    int fpy = find_parent(p,y);

    //if same parent then no need to take union
    if(fpx == fpy){
        return;
    }

    p[fpy] = fpx;
}

int main(){
    int n;
    int x,y;
    cin>>n;
    int r;
    cin>>r;
    vector<int>p(n+1);

    //everyone is parent of oneself
    for(int i=1;i<=n;i++){
        p[i] = i;
    }

    set<int>s;

    for(int i=0;i<r;i++){
        cin>>x>>y;
        union_(x,y,p);
    }

    //inserting the unique parents
    for(int i=1;i<=n;i++){
        s.insert(find_parent(p,i));
    }

    cout<<s.size()<<endl;
}
