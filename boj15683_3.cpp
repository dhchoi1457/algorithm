// boj 15683
// 감시 _ 다시풀기 

//실수했던거 - cctv size를 잘못체크함
//백트래킹시 - 지역변수로해야될걸 전역변수로함


#include <bits/stdc++.h>
using namespace std;

int N, M;

struct CCTV
{
	int num, y, x;	
};


CCTV cctv[10];
int board[10][10];
int ret;

const int dy[4]= {0,-1,0,1};
const int dx[4]= {1,0,-1,0};


int cctv_ind;

void check(){
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cout << board[y][x] <<' ';
		}
		cout <<'\n';
	}
	cout <<'\n';
}

void upd(int dir, int y, int x){
	dir = dir%4;
	int ny = y;
	int nx = x;
	while(1){
		ny = ny + dy[dir];
		nx = nx + dx[dir];
		if(ny <0 or ny>= N or nx<0 or nx>=M) break;
		if(board[ny][nx]==6) break;
		board[ny][nx] = 9;
	}

}

void dfs(int now){
 	if(now == cctv_ind){

 		//맵돌면서 빈공간 세기
 		int cnt=0;
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				if(board[y][x]==0) cnt++;
			}
		} 	

		if(cnt < ret){
			ret = cnt;
			//cout << "ret:" << ret <<'\n';
		}	
 		return;
 	}

 	//현재 cctv의 방향을 정해서 감시구역 채우기
	CCTV cur = cctv[now];

	//백업용(계속 리셋 필요)
	int backup[10][10]; // 이게 전역변수면 안됨ㅠㅜ
	//어디서 부르던 이전 임시 값이 아니라, 전역값에서 가져와지기 때문
	
 	for(int dir=0; dir < 4; dir++){
 		//map backup
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				backup[y][x] = board[y][x];
			}
		}


		//map update
 		if(cur.num == 1){
 			upd(dir,cur.y,cur.x);
 		}
 		if(cur.num == 2){
 			upd(dir,cur.y,cur.x);
 			upd(dir+2,cur.y,cur.x);
 		}
 		if(cur.num == 3){
 			upd(dir,cur.y,cur.x);
 			upd(dir+1,cur.y,cur.x);
 		}
 		if(cur.num == 4){
 			upd(dir,cur.y,cur.x);
 			upd(dir+1,cur.y,cur.x);
 			upd(dir+2,cur.y,cur.x);
 		}
 		if(cur.num == 5){
 			upd(dir,cur.y,cur.x);
 			upd(dir+1,cur.y,cur.x);
 			upd(dir+2,cur.y,cur.x);
 			upd(dir+3,cur.y,cur.x);	
 		}

 		dfs(now+1);
 		
 		//check();

 		//map recover
 		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				board[y][x] = backup[y][x];
			}
		}
		

 	}
 }


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N  >> M;

	//입력 
	cctv_ind =0;
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cin >> board[y][x];

			if(board[y][x]>=1 and board[y][x]<=5){
				cctv[cctv_ind].y = y;
				cctv[cctv_ind].x = x;
				cctv[cctv_ind].num = board[y][x];
				cctv_ind++;
			}
		}
	}
	ret = 1e7;
	
	//cout << "cctv_ind:"<<cctv_ind << '\n';
	//0번째 cctv부터 방향세팅 시작
	dfs(0);

	cout << ret <<'\n';

	return 0;
}

 