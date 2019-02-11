//boj 1926
// 그림 
// 왜 nx ny가 업데이트가 안될까ㅠㅜ


#include <bits/stdc++.h>
using namespace std;

#define X first;
#define Y second;

int board[502][502]; // map
int vis[502][502]; // visited check
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	//map 입력 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
	}
	int cnt=0; // 섬갯수  
	int mx =0; // 섬 최대 너비

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){ // starting point iter
			if(board[i][j]==0 or vis[i][j]==1) continue; // 이미 방문했으면 continue
			cout << i<< " start " << j << '\n';
			cnt++;
			cout << "cnt:" << cnt << '\n';
			queue<pair<int,int> > Q;
			vis[i][j] = 1; //시작지점 방문. 이거 실수하기 쉽다. 
			Q.push({i,j});
			
			int area=0;//현재 탐색하는 섬 너비;
			while(!Q.empty()) // i,j를 시작점으로 BFS 동작
			{
				area++;
				auto cur = Q.front(); Q.pop();
				for(int dir =0; dir<4; dir++)
				{
					cout << cur.X;
					cout << "?? " << dx[dir] << '\n'; 
					int nx = (int) cur.X + dx[dir];
					cout << "nx: "<< nx << '\n';
					int ny = cur.Y + dy[dir];
					cout << "ny: "<< ny << '\n';
					cout << ny << '\n';
					if(nx<0 or nx>=N or ny<0 or ny >=M ) continue;
					if(vis[nx][ny]==1 or board[nx][ny]!=1 ) continue;
					
					cout << "nx ny" << nx << " " << ny << '\n';
					vis[nx][ny]=1; // 범위 맞고, 이전에 방문했던거 아니면서 방문가능지역이면 방문
					Q.push({nx,ny}); //방문가능지역 push
				}	
			}
			mx= max(mx,area);
		}
	}

	cout << cnt <<'\n' << mx << '\n';
	return 0;
}