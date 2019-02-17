// boj 7562
// 나이트의 이동


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int T,N;
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int board[302][302]; // map 이거 input 형태에 따라 조절해야됨. string할지 int할지. 이거떄매 틀렸었음.
int dist[302][302]; // visited check

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for(int tc=0; tc <T; tc++){
		cin >> N;

		for(int n=0; n<N; n++)
		{
			fill(board[n],board[n]+N,0);
			fill(dist[n],board[n]+N,-1);
		}

		int x, y;
		cin >> x >> y;

		int tx, ty;
		cin >> tx >> ty;

		queue<pair<int,int>> Q;

		Q.push({x,y});
		dist[x][y]=0;
		
		while(!Q.empty())
		{
			auto cur = Q.front(); Q.pop();

			if(cur.X == tx and cur.Y == ty){
				break;
			}

			for(int dir=0; dir<8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if(nx<0 or nx>=N or ny<0 or ny>=N){
					continue;
				}
				if(dist[nx][ny]>=0) continue;
				Q.push({nx,ny});
				dist[nx][ny] = dist[cur.X][cur.Y]+1;
			}
		}
		cout << dist[tx][ty] << '\n';
	}
		
	return 0;
}