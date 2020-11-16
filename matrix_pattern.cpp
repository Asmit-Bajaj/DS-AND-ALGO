#include<bits/stdc++.h>
using namespace std;

bool check(int x,int y,int r,int c){
	if(x < 0 || x >= r || y < 0 || y>=c)
		return false;
	else
		return true;
}

int dir_r[] = {-1,0,0,+1,-1,-1,+1,+1};
int dir_c[] = {0,-1,+1,0,-1,+1,-1,+1};

int main(){
	int r,c;
	cin>>r>>c;

	int ans[r][c];

	int ci,cj;
	cin>>ci>>cj;

	queue<pair<int,int> >q;
	q.push(make_pair(ci,cj));
	pair<int,int>curr;
	int visited[r][c];

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			visited[i][j] = 0;
		}
	}

	ans[ci][cj] = 0;

	int x,y;
    visited[ci][cj] = 1;

	while(!q.empty()){
		curr = q.front();
		q.pop();
		//cout<<"hii";

		for(int i=0;i<8;i++){
            x = dir_r[i]+curr.first;
            y = dir_c[i]+curr.second;

			if(visited[x][y] == 0 && check(x,y,r,c)){
					q.push(make_pair(x,y));
					ans[x][y] = ans[curr.first][curr.second]+1;
					//cout<<ans[x][y]<<endl;
					visited[x][y] = 1;
			}
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
