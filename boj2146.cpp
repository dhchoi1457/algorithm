// boj 2146
// 다리만들기

// 1.지도에서 먼저 대륙을 구분한다(dfs든 bfs든)
// 2. bfs로 다리놓는 경로를 탐색한다

// 실수 1. 다리의 갯수(bfs의 거리)를 체크할때 dist배열이 아니라 cnt로 했음
// --> 그래서 탐색할떄마다 cnt가 올라가 제대로 체크 못함

// 실수 2. 새로시작할때는 매번 Q와 visited가 리셋되어있어야함.
// --> 안그러면 Q에 잔여물이 있어서 탐색 루트가 이상해지고,
// --> 이전에 다리 건설시 참고했던 경로로 못가게됨. 주의

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N;
int board[102][102];
int visited[102][102]; //
int dist[102][102];
int min_b= 9999999;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// 맵 입력
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
		}
	}

	queue<pair<int,int>> Q;

	//BFS 1.섬을 구분하기
	int chk=1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j]!=1) continue; // 0이거나 이미 체크한 대륙인 경우 continue;
			chk++; //새로운 대륙 
			Q.push({i,j});
			board[i][j]= chk;
			
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();

				for(int dir=0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if(nx<0 or nx>=N or ny <0 or ny>=N ) continue;
					if(board[nx][ny]!=1) continue;
					board[nx][ny]=chk;
					Q.push({nx,ny});
				}
			}
		}
	}


	//제대로 대륙 구분이 되었나? OK
	// for(int i=0; i<N; i++ ){
	// 	for(int j=0; j<N; j++){
	// 		cout << board[i][j] <<' ';
	// 	}
	// 	cout << '\n';
	// }


	// BFS 2. 다리놓기
	int now;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j]==0 or visited[i][j]==1) continue; //시작은 대륙이면서 방문안한 곳에서 해야함
			//cout << "새로운 스타트지점 i,j ,대륙:" << i << ','  << j << " / " <<board[i][j]<< '\n';
			queue<pair<int,int>> Q;
			now = board[i][j]; // 현재 대륙
			dist[i][j]=0;
			Q.push({i,j});
			int cnt;
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				//cout << "탐색중 cur:" << cur.X  <<','<< cur.Y << '\n';

				if(board[cur.X][cur.Y]!=0 and board[cur.X][cur.Y]!=now){
					cnt = dist[cur.X][cur.Y]-1; // 다른 대륙 도착 직전까지만 다리놓음
					//cout << "cnt:"<< cnt<< '\n';
					break;
				}

				for(int dir = 0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					//cout << "nx, ny / board " << nx << ' ' << ny << " / " << board[nx][ny] << '\n';
					if(nx<0 or nx >=N or ny <0 or ny >=N) continue;					
					if(board[nx][ny]==now or visited[nx][ny]==1) continue;//같은 대륙인곳, 방문했던 곳은 탐사할 필요 없음
					visited[nx][ny]=1;
					Q.push({nx,ny});
					dist[nx][ny] = dist[cur.X][cur.Y]+1;
				}	
			}

			if(cnt >=1 and min_b> cnt){min_b = cnt;}
			for(int k=0; k<N; k++){
				fill(visited[k],visited[k]+N,0);
			}
		}
	}	

	cout << min_b <<'\n';
	return 0;
}
