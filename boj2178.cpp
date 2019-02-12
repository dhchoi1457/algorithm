//boj 2178
// 미로탐색

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 연산 안됨.. 

string board[102]; // map 이건 연달아서 input으로 들어오므로 string으로 받는다 
int dist[102][102]; // visited check, 거리도 체크
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	//map 입력 
	for(int i=0; i<N; i++) 
		cin >> board[i];
	
	for(int i = 0; i < N; i++) fill(dist[i],dist[i]+M,-1); // -1로 거리 초기화
	queue<pair<int,int> > Q;
	dist[0][0] = 1; //시작지점 방문. 이거 실수하기 쉽다. 
	Q.push({0,0});
	
	while(!Q.empty()) // BFS동작
	{
		auto cur = Q.front(); Q.pop();
		for(int dir =0; dir<4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx<0 or nx>=N or ny<0 or ny >=M ) continue;
			if(dist[nx][ny]>0 or board[nx][ny]!='1' ) continue;
			
			dist[nx][ny]=dist[cur.X][cur.Y]+1; // 방문체크 + 길이체크
			Q.push({nx,ny}); //방문가능지역 push
		}	
	}
	cout << dist[N-1][M-1]<< '\n';
	return 0;
}