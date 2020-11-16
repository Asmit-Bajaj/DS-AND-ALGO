#include <bits/stdc++.h>
using namespace std;

int main() {
    int test,v;
    cin>>test;

    while(test--){
        cin>>v;
        int mat[v+1][v+1];
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                cin>>mat[i][j];
            }
        }
        //include every vertex in between to check whether it reduces the distance or not
        for(int k=1;k<=v;k++){
            for(int i=1;i<=v;i++){
                for(int j=1;j<=v;j++){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(mat[i][j] == 10000000)
                    cout<<"INF ";
                else
                    cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
