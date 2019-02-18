// boj 2573
// 빙산

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[302][302];
int board2[302][302];
int visit[302][302];
int N,M;


void board_update(){
		//map update
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			
			int cnt=0;
			for(int dir=0; dir<4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
				if(board[nx][ny]==0){cnt++;}
			}
			board2[i][j]= max(0,board[i][j]-cnt);
		}
	}

	for(int i=0; i<N; i++){
		//동시에 visit 초기화
		fill(visit[i],visit[i]+M,0);

		//board 갱신
		for(int j=0; j<M; j++){
			board[i][j]= board2[i][j];
		}
	}

}


int bfs(){
	queue<pair<int,int>> Q;
	int cnt =0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(visit[i][j]==1 or board[i][j]==0) continue;
			cnt++;
			Q.push({i,j});
			visit[i][j]=1;

			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if(nx<0 or nx>=N or ny <0 or ny >=M) continue;
					if(visit[nx][ny]==1 or board[nx][ny]==0) continue;
					Q.push({nx,ny});
					visit[nx][ny]=1;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	//board input
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
	}

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<M; j++){
	// 		cout << board[i][j] << '\t';
	// 	}
	// 	cout << '\n';
	// }

	int year =0;
	int ans;
	while(1){
		
		ans = bfs();
		if(ans>1){
			cout << year << '\n';
			break;
		}

		if(ans==0){
			cout << 0 <<'\n';
			break;
		}

		board_update();
		year++;
	}


	return 0;
}