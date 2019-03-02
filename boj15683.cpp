// boj 15683
// 감시 

// 삼성 기출문제의 시작.
// 쌩 시뮬레이션 문제인데, 내가 상황에 맞게 코드를 사용하지 못한다.
// 연습, 연습, 연습
// 풀이는 https://joonas.tistory.com/55 참고했음
// 다시풀것.


#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;

const int INF = 0x3F3F3F3F;

#define X first
#define Y second

#define U (1<<0)
#define R (1<<1)
#define D (1<<2)
#define L (1<<3)

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<int> moving[5] = {
	{U, R, D, L}, // CCTV 1번이 볼수있는 방향들
	{U|D, R|L},   // CCTV 2번이 볼수있는 방향들
 	{U|R, U|L, D|R, D|L},	// CCTV 3번이 볼수있는 방향들
 	{U|R|L, D|R|L, R|U|D, L|U|D},	// CCTV 4번이 볼수있는 방향들
 	{U|R|L|D}	// CCTV 5번이 볼수있는 방향들
};



int N,M;
int board[10][10];

int direct[10]; // 순서대로 등장한 cctv의 방향
vector<int> cctv; // 순서대로 등장한 cctv의 종류
vector<ii> cctvs; // 순서대로 등장한 cctv의 위치



int solve(int cur){
	if(cur==(int)cctv.size()){ //모든 cctv의 방향이 결정됨(cctv의 갯수만큼 방향이 셋팅)
		int temp[10][10];
		memcpy(temp,board,sizeof(temp)); // board를 복사한곳에서 작업

		for(int i=0; i< (int)cctv.size(); i++ ){
			int x = cctvs[i].X;
			int y = cctvs[i].Y;

			int type = cctv[i]-1; // 맵에서는 cctv 번호가 1부터 시작

			for(int j=0; j<4; j++){
				if(moving[type][direct[i]] & (1<<j)){ //cctv 타입별로 현재 보는 방향과, 탐색방향(j)가 겹치는 부분만 탐색

					for(int ny = y, nx=x;; ny +=dy[j], nx+=dx[j]){
						if (ny < 0 or ny >= M or nx < 0 or nx >= N or temp[nx][ny] == 6) break; // 벽만나거나 벗어날때까지 반복
						temp[nx][ny]= -1;
					}
				}
			}	
		}

		int sum = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				sum += temp[i][j] == 0; //사각지대 갯수 count

		return sum;
	}

	//cctv 방향이 다 정해지기 전이면
	int ref = INF;
	for(int i=0; i < (int)moving[cctv[cur]-1].size(); i++){ // cctv번호에 맞게 방향 조절
 		direct[cur]=i; 
		ref = min(ref, solve(cur+1));
	}
	return ref;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	// 맵 입력
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];

			if(board[i][j]>=1 and board[i][j]<=5){
				cctv.push_back(board[i][j]);
				cctvs.push_back({i,j});
			}
		}
	}

	int ans = solve(0);
	cout << ans << '\n';

	return 0;
}
