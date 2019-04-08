
// swea 5650
// 핀볼게임
#include <bits/stdc++.h>
using namespace std;

int N;

int board[104][104];

const int dy[4]={0,0,-1,1};
const int dx[4]={1,-1,0,0};
//블록번호, dir
int meet_block[6][4]={
	{0,1,2,3}//빈공간
	//1번블록
	,{1,3,0,2}
	//2번블록 
	,{1,2,0,3}
	//3번블록
	,{2,0,3,1}
	//4번블록
	,{3,0,1,2}
	//5번블록 
	,{1,0,3,2}
};

int cnt;
int sy,sx;

void simul(int y, int x, int dir){
	int ny = y+dy[dir];
	int nx = x+dx[dir];

	if(board[ny][nd]===1){
		return;
	}

	if(ny == sy and nx == sx){
		return;
	}

	if(board[ny][nx]>=1 and board[ny][nx]<=5){
		int block = board[ny][nx];
		int nd = meet_block[block][dir];
		cnt++;
		simul(ny,nx,nd);
	}

	if(board[ny][nx]>=6 and board[ny][nx]<=10){
		//웜홀만났을떄
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	//벽면에 맞아도 튕겨야하므로 주변을 벽5로 감싸줄것
	for(int y=1; y<=N; y++){
		for(int x=1; x<=N; x++){
			cin >> board[y][x];
		}
	}

	for(int t=0; t<=N+1; t++){
		board[t][0]=5;
		board[t][N+1]=5;
		board[0][t]=5;
		board[N+1][t]=5;
	}

	// //board test - good
	// for(int y=0; y<=N+1; y++){
	// 	for(int x=0; x<=N+1; x++){
	// 		cout << board[y][x] << ' ';
	// 	}
	// 	cout << '\n';
	// }



	//시뮬레이션 
	for(int y=1; y<=N; y++){
		for(int x=1; x<=N; x++){

			if(board[y][x]!=0) continue;
			
			sy = y;
			sx = x;
			for(int dir=0; dir<4; dir++){
				cnt = 0;
				simul(y,x,dir);
			}

		}
	}



	return 0;
}