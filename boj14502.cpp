// boj 14502
// 연구소

#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int backup[10][10];
int visited[10][10];

int N, M, ret;

const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};


void bk_map(){
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			backup[y][x] = board[y][x];
		}
	}
}

void check(){
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cout << board[y][x] << ' ';
		}
		cout <<'\n';
	}
	cout <<'\n';
}

void check_b(){
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cout << backup[y][x] << ' ';
		}
		cout <<'\n';
	}
	cout <<'\n';
}


struct POSI{
	int y, x;
};

void bfs(){

	queue<POSI> q;
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			visited[y][x]=0;
		}
	}


	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			if(backup[y][x]==2){
				POSI p;
				p.y = y;
				p.x = x;
				q.push(p);
				visited[y][x]=1;
			}
		}
	}

	//bfs ㄱㄱ
	while(!q.empty()){
		POSI cur = q.front(); q.pop();

		for(int dir=0; dir<4; dir++){
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if(ny<0 or ny >=N or nx <0 or nx>=M) continue;
			if(backup[ny][nx]!=0 or visited[ny][nx]==1) continue;
			backup[ny][nx]=2;
			visited[ny][nx]=1;
			POSI np;
			np.y =ny;
			np.x =nx;
			q.push(np);
		}

	}

	int candi=0;
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			if(backup[y][x]==0){
				candi++;
			}
		}
	}

	//cout << "candi:" <<candi << ", ret :" << ret <<'\n'; 
	//check_b();

	if(candi > ret){
		ret=candi;
	}


}

void dfs(int count, int y, int x){
	if(count==3){
		bk_map();
		//check_b();
		bfs();
		//check();
		return;
	}

	for(int ny = 0; ny<N; ny++){
		for(int nx = 0; nx<M; nx++){
			if(board[ny][nx]==0){
				board[ny][nx]=3;
				dfs(count+1,ny,nx);
				board[ny][nx]=0;
			}
		}
	}


}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >>M;

	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cin >> board[y][x];
		}
	}

	ret = -1e7;
	//check();

	//벽 3개 세우기
	dfs(0,0,0);

	//dfs에서 각각 3개 세운 케이스마다,
	//바이러스 퍼트리기 bfs 하면 끝

	cout << ret <<'\n';
	return 0;
}
  