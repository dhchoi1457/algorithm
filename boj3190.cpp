// boj 3190
// 뱀

// 삼성 기출
// bfs
// 왜터지지

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct POSI
{
	int y ,x;
};


struct MOVE
{
	int x;
	char c;
};

int dy[4] ={0,-1,0,1};
int dx[4] ={1,0,-1,0};

int board[102][102];
int N, K, L;

int main(){
	cout << "treu!!" <<'\n';
	cin >> N;
	cout << "N:" << N <<'\n'; 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			board[i][j]=0;
		}
	}

	cin >> K ;
	cout << "K:" << K <<'\n'; 

	for(int i=0; i<K; i++){
		int y,x;
		cin >> y >> x;
		board[y][x] = 2;
	}

	cin >> L;
	cout << "L:" << L <<'\n'; 
	// 뱀 길이 조절하는 큐
	queue<POSI> snake;

	//움직임 기억하는 큐 
	queue<MOVE> mq;
	for(int i=0; i<L; i++){
		MOVE cur;
		cin >> cur.x >> cur.c;
		mq.push(cur); 
	}

	cout << "NOW SIMUL" <<'\n'; 
	//시뮬레이션 시작
	board[0][0]=9;

	int now_y=0;
	int now_x=0;
	
	int dir =0; // 처음 방향은 오른쪽

	int time =0;

	MOVE now_dir;
	now_dir = mq.front();

	while(1){
		cout << "ing~" << '\n';
		time++;

		if(time == now_dir.x){
			mq.pop();
			if(now_dir.c=='L'){
				dir = (dir+1)%4;
			}
			if(now_dir.c=='D'){
				dir = (dir+3)%4;
			}

			if(!mq.empty()){
				now_dir = mq.front();
			}
		}

		int nxt_y = now_y + dy[dir];
		int nxt_x = now_x + dx[dir];
		cout << "nxt y,x" << nxt_y <<',' << nxt_x <<'\n';
		cout << board[nxt_y][nxt_x] <<'\n';
		if(nxt_y<0 or nxt_y >=N or nxt_x <0 or nxt_x >=N){
			cout << N <<'\n';
			cout << "treu!!" <<'\n';
			break;
		}
		if(board[nxt_y][nxt_x]==9){break;}
		//사과먹으면 길이만 증가 
		if(board[nxt_y][nxt_x]==2){
			board[nxt_y][nxt_x]=1;
			POSI cur;
			cur.y = nxt_y;
			cur.x = nxt_x;
			snake.push(cur);
		}

		//사과 아니라 빈자리면
		if(board[nxt_y][nxt_x]==0){
			
			//꼬리 자리 제거 
			POSI cur1;
			cur1 = snake.front(); snake.pop();
			board[cur1.y][cur1.x]=0;

			//머리는 움직임 
			board[nxt_y][nxt_x]=1;
			POSI cur2;
			cur2.y = nxt_y;
			cur2.x = nxt_x;
			snake.push(cur2);	
		}
	}
	cout << time <<'\n';
	return 0;
}



 