// boj 2206
// 벽부수고 이동
// 무엇을 고치면 될까?
// Not yet, 재도전 후 pass 
// 1.continue하는 범위 수정
// 2.인풋도 잘못되어있었음
// 3.dist[N-1][M-1] = -1로 초기화해서 활용했던거 수정

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct pos
{
	int x,y,bomb;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[1002];
int visit[1002][1002][2]; // visited check
int dist[1002][1002];
int N,M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; // N= 6 M=4;
	
	for(int i=0; i<N; i++)
	{
		cin >> board[i];
	}

	queue<pos> Q; // struct에 맞는 Q
	pos s;
	s.x = 0; s.y=0; s.bomb=0; //시작점. 사용폭파 횟수 0 --> 1번 사용가능
	Q.push(s);
	visit[s.x][s.y][0]=1;
	visit[s.x][s.y][1]=1; // **시작점은 폭탄쓰든안쓰든 1

	dist[s.x][s.y]=1;
	//dist[N-1][M-1]=-1; // **안되는 경우에 출력하려고 이렇게 초기화 해두고 하면 문제생김

	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();

		if(cur.x == N-1 and cur.y ==M-1){ // 목표도달
			cout << dist[N-1][M-1] << '\n';
			return 0;
		}
		int nbomb = cur.bomb;

		for(int dir=0; dir<4; dir++){
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			
			if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
			if(visit[nx][ny][nbomb]==1 or board[nx][ny]!='0') continue;

			pos nxt;
			nxt.x = nx; nxt.y = ny; nxt.bomb=nbomb;
			
			Q.push(nxt);
			visit[nx][ny][nbomb]=1;
			dist[nx][ny] = dist[cur.x][cur.y]+1;
		}

		if(nbomb==0){ // 아직 bomb 미사용?
			for(int dir=0; dir<4; dir++){
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				//cout << "nx, ny : " << nx << ' ' << ny <<'\n';
				if(nx<0 or nx >=N or ny <0 or ny >=M) continue;
				if(visit[nx][ny][nbomb]==1 or board[nx][ny]=='0') continue;
				pos nxt;
				nxt.x = nx; nxt.y = ny; nxt.bomb=1; // 사용. 이제 사용 불가 
				Q.push(nxt);
				visit[nx][ny][nbomb]=1; // 사용된 상태로는 사용된 상태로서의 bfs가 전개 됨. 
				dist[nx][ny] = dist[cur.x][cur.y]+1;
			}
		}
	}	

	cout << "-1" << '\n';
	return 0;
}