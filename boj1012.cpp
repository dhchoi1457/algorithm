#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int T,N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int k = 0; k<T; k++)
	{
		int board[52][52]={}; // map 이거 input 형태에 따라 조절해야됨. string할지 int할지. 이거떄매 틀렸었음.
		int vis[52][52]={}; // visited check

		cin >> N >> M;

		int num;
		cin >> num;
		for(int l=0; l<num; l++) //배추 위치 입력
		{	
			int x,y;
			cin >> x >> y;
			board[x][y]=1;
		} 

		int cnt =0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(board[i][j]!=1 or vis[i][j]==1){
					continue;
				}
				queue<pair<int,int>> Q;
				Q.push({i,j});
				cnt++; //시작점 갯수만 세면 된다.
				vis[i][j]=1;

				while(!Q.empty())
				{
					auto cur = Q.front(); Q.pop();
					
                    for(int dir=0; dir<4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
						if(vis[nx][ny]==1 or board[nx][ny]!=1) continue;
						Q.push({nx,ny});
						vis[nx][ny]=1;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}