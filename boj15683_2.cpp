// boj 15683 
// 감시 
// 바킹독님 풀이 참고


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,m;

int board_original[10][10];
vector<pair<int,int> > cctv;

bool OOB(int a, int b){
	return (a<0 or a>=n or b<0 or b>=m);
}

// (x,y)에서 dir방향으로 진행하면서 벽을 만날떄 까지 모든 칸을 7로 만든다. 
// board[][10]이 어떤게 넘어오는지 살펴볼것
void upd(int board[][10], int x, int y, int dir){
	dir %= 4;

	while(1){
		x+=dx[dir];
		y+=dy[dir];
		if(OOB(x,y)) break;
		if(board[x][y]==6) break;
		if(board[x][y]!=0) continue; // CCTV 뛰어넘기
		board[x][y] = 7;		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(20);
	cin >> n >> m;

	int mn = 0; // 사각지대의 최소 크기(답)

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board_original[i][j];

			if(board_original[i][j]!=0 and board_original[i][j]!=6){
				cctv.push_back({i,j});
			}
			if(board_original[i][j]==0) mn++; // 여기는 사각지대(#표시 아닐떄)
		}
	}

	// mn은 사각지대의 최소크기가 되어야함. 현재는 빈칸의 갯수
	// 1 << (2*cctv.size()) 는 4의 cctv.size() 제곱승을 의미.
	// 각 cctv는 4개의 방향을 가지므로 4의 cctv.size() 제곱만큼의 가능성이 존재(각 cctv가 4방향이고, cctv의 모든 조합을 고려해야하므로 )
	for(int tmp=0; tmp < (1<<(2*cctv.size())); tmp++){
		// tmp를 4진법으로 뒀을때 각 자리수를 cctv의 방향으로 생각
		// 예를 들어 tmp 45 = 16*2+ 4*3 + 1*1 인 경우 , 0번쨰 cctv는 1번방향 / 1번쨰 cctv는 3번방향 / 2번쨰 cctv는 2번방향
		int brute = tmp;
		int board[10][10];

		//원래 보드 그대로 복사
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				board[i][j] = board_original[i][j];
			}
		}

		for(int i=0; i< cctv.size(); i++){
			int dir = brute % 4; // i번쨰 자리의 방향을 추출(cctv갯수만큼 계속 나눠져감)
			brute /= 4; //해당 부분의 자리를 제거. 계속 맨 뒤로 보내는 느낌. 4로나눌떄 나머지 나오게

			int x = cctv[i].X;
			int y = cctv[i].Y;

			//1번 cctv
			if(board[x][y]==1){
				upd(board,x,y,dir);
			}

			if(board[x][y]==2){
				upd(board,x,y,dir); upd(board,x,y,dir+2);
			}

			if(board[x][y]==3){
				upd(board,x,y,dir); upd(board,x,y,dir+1);
			}

			if(board[x][y]==4){
				upd(board,x,y,dir); upd(board,x,y,dir+1); upd(board,x,y,dir+2);
			}

			if(board[x][y]==5){
				upd(board,x,y,dir); upd(board,x,y,dir+1); upd(board,x,y,dir+2); upd(board,x,y,dir+3);
			}
		}
		//각 시뮬레이션에서 빈칸의수 카운트 
		int val = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				val+=(board[i][j]==0);
			}
		}

		//답 업데이트 
		if(mn>val)mn=val;
	}

	//시뮬 끝남
	cout << mn;
	return 0;
}
