// boj 7569
// 토마토 3차원

#include <bits/stdc++.h>
using namespace std;

//#define X first
//#define Y second

// 3- dim
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int board[102][102][102];
int dist[102][102][102]; // time 체크용
queue<pair<pair<int, int>, int>> Q; //3차원 queue

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M,H; // N이 x축 M이 y축 H가 z축 이거 적어놓고 하기 

	cin >> M >> N >> H;


	//time default -1; tomato 0
	for(int h=0; h<H; h++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){

					cin >> board[i][j][h];
					dist[i][j][h]=-1;
					if(board[i][j][h]==1)
					{
						Q.push({{i,j},h});
						dist[i][j][h]=0;
					}
			}	
		}
	}


	// start BFS
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for(int k = 0; k<6; k++)
		{
			int nx = cur.first.first + dx[k];
			int ny = cur.first.second + dy[k];
			int nz = cur.second + dz[k];

			if(nx<0 or nx>=N or ny<0 or ny>=M or nz <0 or nz >=H) continue; // board 범위 벗어나면
			if(dist[nx][ny][nz]>=0 or board[nx][ny][nz]!=0) continue; // 이미 방문한적 있으면(dist >=0) or 지나갈수없는 지역이면
			Q.push({{nx,ny},nz});
			dist[nx][ny][nz] = dist[cur.first.first][cur.first.second][cur.second]+1;
			board[nx][ny][nz] = 1;
		}
	}



	int mx=-1e9;
	for(int h=0; h<H; h++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(mx < dist[i][j][h]){mx = dist[i][j][h];} 
				if(board[i][j][h]==0){
					mx = -1; break;}
			}
			if(mx==-1){break;} // 3중탈출 break
		}
		if(mx==-1){break;}
	}

	cout << mx << '\n';
	return 0;
}

