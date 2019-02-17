// boj 10026
// 적록색약
// 두번 bfs 돌리고,
// 처음에 돌리면서 적록색맹에 맞추어 board를 변환해놓음
// --> 걍 끝나고 탐색해서 수정해도 괜찮

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[102];
int visit[102][102]; // visited check

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> board[i];
	}

	int cnt_n=0; // 적록색맹이 아닌자들

	//정상인 탐색, 탐색하면서 G를 R로 전환
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			auto now_color = board[i][j]; // 시작지점의 현재컬러
			if(now_color=='G'){board[i][j]='R';}
			
			if(visit[i][j]==1) continue;
			cnt_n++;

			queue<pair<int,int>> Q;
			Q.push({i,j});
			visit[i][j]=1;

			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				for(int dir=0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if(nx<0 or nx >=N or ny <0 or ny >=N) continue;
					if(visit[nx][ny]==1 or board[nx][ny]!=now_color) continue;
					Q.push({nx,ny});
					visit[nx][ny]=1;
				}
			}
		}
	}
	cout << cnt_n << '\n';



	for(int j=0; j<N; j++)
		fill(visit[j],visit[j]+N,0); //visit 리셋
	
	int cnt_y=0; //적록생맹인자들은 R=G
	//적록색맹 탐색, 앞에서 탐색하면서 G를 R로 전환
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j]==1) continue;
			cnt_y++;
			auto now_color = board[i][j]; // 시작지점의 현재컬러

			queue<pair<int,int>> Q;
			Q.push({i,j});
			visit[i][j]=1;

			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				for(int dir=0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if(nx<0 or nx >=N or ny <0 or ny >=N) continue;
					if(visit[nx][ny]==1 or board[nx][ny]!=now_color) continue;
					Q.push({nx,ny});
					visit[nx][ny]=1;
				}
			}
		}
	}
	cout << cnt_y << '\n';


	return 0;
}