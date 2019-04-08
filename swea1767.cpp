
// swea 1767
// 프로세서 연결하기 
// 맵에서 count하고 업데이트하는 부분만 수정하면 될듯?


#include <bits/stdc++.h>
using namespace std;

struct CORE{
	int y, x, connect;
};

int N, ret;
int board[14][14];

CORE core[14];
int core_size;

int cnt_core=-1e7;

const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

void check(){
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cout << board[y][x] << ' ';
		}
		cout <<'\n';
	}
	cout <<'\n';
}

int upd(int dir, int y, int x){
	int is_ud = 0;
	int ny = y;
	int nx = x;
	while(1){
		ny = ny + dy[dir];
		nx = nx + dx[dir];
		if(nx<0 or nx>=N or ny<0 or ny>=N) break;
		if(board[ny][nx]==1) break;
		board[ny][nx]=9;
		if(nx==0 or nx==N-1 or ny==0 or ny==N-1){is_ud=1; break;}
	}
	return is_ud;
}


void dfs(int core_ind){

	if(core_ind == core_size){

		check();
		int candi=0;
		for(int s=0; s<core_size; s++){
			if(core[s].connect==1) candi++;
		}

		// 더 많이 연결되면 업데이트 
		if(cnt_core<candi){
			cnt_core=candi;
			
			int cnt_line=0;
			for(int y=0; y<N; y++){
				for(int x=0; x<N; x++){
					if(board[y][x]==9) cnt_line++;
				}
			}

			//코어 수 갱신대면 걍 업데이트 
			ret = cnt_line;
		}
		else if(cnt_core==candi){
			//기존이랑 연결된 코어수 같으면 
			int cnt_line=0;
			for(int y=0; y<N; y++){
				for(int x=0; x<N; x++){
					if(board[y][x]==9) cnt_line++;
				}
			}

			// 길이가 최소일때만 업데이트 
			if(ret> cnt_line)  ret = cnt_line;			
		}

		return;
	}

	if(core[core_ind].connect==1){
		dfs(core_ind+1);
	}else{
		//4방향으로 돌면서 탐색, 연결안되면 선 없앤다

		int backup[14][14];

		//맵 백업
		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				backup[y][x]= board[y][x];
			}
		}

		for(int dir=0; dir<4; dir++){
			int y = core[core_ind].y;
			int x = core[core_ind].x;
			
			int is_update = upd(dir,y,x);

			//연결가능 - 걍 dfs진행 // 백트래킹
			if(is_update==1){
				dfs(core_ind+1);

				for(int y=0; y<N; y++){
					for(int x=0; x<N; x++){
						board[y][x]= backup[y][x];
					}
				}

			}else{
				for(int y=0; y<N; y++){
					for(int x=0; x<N; x++){
						board[y][x]= backup[y][x];
					}
				}

				dfs(core_ind+1);

				for(int y=0; y<N; y++){
					for(int x=0; x<N; x++){
						board[y][x]= backup[y][x];
					}
				}
			}
		}
	}


}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	// 맵입력, 프로세서 위치도 입력
	core_size=0;

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cin >> board[y][x];
			if(board[y][x]==1){
				core[core_size].y=y;
				core[core_size].x=x;
				core[core_size].connect=0;
				core_size++;
			}
		}	
	}

	//벽에 붙어있으면 이미 연결됨
	for(int i=0; i<core_size; i++){
		if(core[i].y==0 or core[i].y==N-1 or core[i].x==0 or core[i].x==N-1){
			core[i].connect=1;
		}
	}

	dfs(0);

	cout << ret <<'\n';

	return 0;
}