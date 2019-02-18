// boj 2468
// 안전영역 

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102];
int visit[102][102];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int mx = -1e9;
	//board input
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			if(board[i][j]>mx){mx=board[i][j];} // 장마철 최대 물높이
		}
	}

	int mx_area = 1;


	for(int m=1; m<mx; m++){

		for(int l =0; l<N; l++)
		{
			fill(visit[l],visit[l]+N,0);
		}

		int cnt = 0;
		queue<pair<int,int>> Q;

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(visit[i][j]==1 or board[i][j]<=m) continue;
				cnt++;
				Q.push({i,j});
				visit[i][j]=1;
				while(!Q.empty())
				{
					auto cur = Q.front(); Q.pop();
					for(int dir = 0; dir<4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx<0 or nx >= N or ny <0 or ny >=N) continue;
						if(visit[nx][ny]==1 or board[nx][ny]<=m) continue;
						Q.push({nx,ny});
						visit[nx][ny]=1;
					}
				}
			}
		}
		//cout << "m:" << m << " cnt:" << cnt << '\n'; 
		if(cnt > mx_area) mx_area =cnt;
	}
		cout << mx_area << '\n';


	return 0;
}