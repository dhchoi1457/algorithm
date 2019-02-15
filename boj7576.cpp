// boj 7576
// 토마토
// 이게 bfs가 시작되는 지점이 여러개.
// 그래서 맨 처음엔 각 지점에서 동시에 bfs를 어떻게 시켜야 하지? 라고 생각했음.
// 그런데 Q의 특성상 FIFO 이므로,
// 새로운 지점 탐색시  기존 거리(시간)+1 만큼이 더걸리기 때문에
// 탐색된 지점들의 시간이 꼬일일이 없음.
// 단순 bfs

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[1002][1002];
int dist[1002][1002]; // time 체크용
queue<pair<int,int>> Q;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M; // M이 가로, N이 세로 이런거 잘 체크.

	cin >> N >> M;
	//cout << N <<"N M" << M << '\n'; 
	//time default -1; tomato 0
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			dist[i][j]=-1;
			if(board[i][j]==1)
			{
				Q.push({i,j});
				dist[i][j]=0;
				//cout << "push :" << i <<' ' << j << '\n';
			}
		}
	}

	// start BFS
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for(int k = 0; k<4; k++)
		{
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];

			if(nx<0 or nx>=M or ny<0 or ny>=N) continue; // board 범위 벗어나면
			if(dist[nx][ny]>=0 or board[nx][ny]!=0) continue; // 이미 방문한적 있으면(dist >=0) or 지나갈수없는 지역이면
			Q.push({nx,ny});
			dist[nx][ny] = dist[cur.X][cur.Y]+1;
			board[nx][ny] = 1;
		}
	}

	int mx=-1e9;

	// cout << "board" << '\n';
	// for(int i=0; i<M; i++){
	// 	for(int j=0; j<N; j++){
	// 		cout << board[i][j] << '\t';
	// 		//if(board[i][j]==0){mx = -1; break;}
	// 		//if(mx < dist[i][j]){mx = dist[i][j];} 
	// 	}
	// 	cout <<'\n';
	// }

	// cout << "dist" << '\n';
	// for(int i=0; i<M; i++){
	// 	for(int j=0; j<N; j++){
	// 		cout << dist[i][j] << '\t';
	// 	}
	// 	cout <<'\n';
	// }

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(mx < dist[i][j]){mx = dist[i][j];} 
			if(board[i][j]==0){mx = -1; ;break;}
		}
		if(mx==-1){break;} // 2중 포문이라 이렇게 해야되나
	}
	cout << mx << '\n';

	return 0;
}

