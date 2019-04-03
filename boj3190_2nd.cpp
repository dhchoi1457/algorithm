// boj 3190
// 뱀

// 삼성 기출
// bfs

#include <bits/stdc++.h>
using namespace std;

int N,K,L;

int apple_y[101];
int apple_x[101];

int t[101];
char t_d[101];

//왼쪽으로 90도 트는 방향
//왼쪽으로갈땐 +3 오른쪽으로갈땐 +1
const int dy[4]= {0,1,0,-1};
const int dx[4]= {1,0,-1,0};




struct POSI{
	int y, x;
};


int board[102][102] = {0,};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cin >> K;
	for(int k=0; k<K; k++){
		int y,x;
		cin >> y >> x;
		board[y-1][x-1]=1; // 사과
	}

	// for(int y=0; y<N; y++){
	// 	for(int x =0; x<N; x++){
	// 		cout << board[y][x]<<' ';
	// 	}
	// 	cout << '\n';
	// }

	cin >> L;
	for(int l=0; l<L; l++){
		cin >> t[l] >> t_d[l];
		//cout << t[l] << ' ' << t_d[l] << '\n';
	}	

	//뱀이 움직인다
	//뱀 초기 길이는 1
	//시작은 0,0
	//방향은 오른쪽

	queue<POSI> snake;	//queue는 fifo. 제일 먼저들어갔던게 꼬리가 되므로 꼬리가 나온다.

	POSI s;
	s.y=0;
	s.x=0;

	board[s.y][s.x]=9;

	// 이거보다 편하게 뱀의 좌표를 업데이트하는 방법 없을까
	// queue로 관리 / 배열로 관리? 
	//배열로 관리한다면 vector로 할수 있을거같은데..

	snake.push(s);
	int snake_len = 1; 
	int dir = 0;//현재 우측방향


	int move=0;

	int time =0;

	int now_y = s.y;
	int now_x = s.x;
	while(true){
		POSI cur;
		cur.y = now_y;
		cur.x = now_x;

		//방향바꾸는 타이밍이 되면 방향바꿈 

		//cout << "t : " << t[move] << '\n';
		if(time == t[move]){
			if(t_d[move]=='L'){
				dir = (dir+3)%4;
				//cout << "L " << dir << '\n';
			}
			if(t_d[move]=='D'){
				dir = (dir+1)%4;	
				//cout << "D " << dir << '\n';
			}
			move++;
		}

		//방향이 정해진걸로 업데이트 
		time++;
		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];
		//cout<<"check time / ny , nx : " << time << " / " << ny << " , " << nx <<'\n'; 

		if(ny<0 or ny>=N or nx<0 or nx>=N) break; //벽에 부딪히면 break
		if(board[ny][nx]==9) break; //자기 몸과 만나면 break

		if(board[ny][nx]==1){
			//사과가 있으면 길이 늘어남, 머리 확장 
			//머리부분의 맵을 업데이트
			snake_len++;
			POSI nxt;
			nxt.y = ny;
			nxt.x = nx;
			board[ny][nx]=9;
			snake.push(nxt);

			now_y=ny;
			now_x=nx;
		}
		if(board[ny][nx]==0){
			//사과없으면 길이 그대로, 머리 확장, 꼬리 아웃
			//머리부분, 꼬리 부분 맵 업데이트
			snake_len++;
			POSI nxt;
			nxt.y = ny;
			nxt.x = nx;
			board[ny][nx]=9;
			snake.push(nxt);
			POSI tail = snake.front(); snake.pop();
			board[tail.y][tail.x]=0;

			now_y=ny;
			now_x=nx;
		}
	}

	//죽을때까지 몇초?
	cout << time << '\n';
	return 0;
}



 