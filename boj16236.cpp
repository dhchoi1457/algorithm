// boj 16236
// 아기상어
// 2018 하반기 삼성전자 ce/im SW역량기출


// x, y 바뀐거 할때는 차분히 잘생각하자.
// 이거하나로 답이 안나옴.
// 미묘한 설계 하나가 틀리면 오답나온다.
// 거의 다 맞아도 그렇다.
// 한 부분만 틀려도 그럼.

#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];

struct SHARK{
	int x, y, time;
};

int shark_size, shark_eat;
SHARK shark;

const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			if(board[i][j]==9){
				shark.x = i;
				shark.y = j;
				shark.time =0;
				shark_size=2;
				shark_eat=0;
				board[i][j]=0;
			}
		}
	}

	bool is_update = true; // 이걸로 잡아먹을수 있는게 있는지 없는지 판단. 없으면 엄마부른다	
	while(is_update){ //잡아먹을수있는거 없으면 끝
		is_update=false;

		bool visited[22][22]={false,}; //false로 초기화

		queue<SHARK> q;
		visited[shark.x][shark.y]= true;
		q.push(shark);

		SHARK candi; //잡아먹을 위치의 후보군(잡아먹으면 샤크가 그리로 가니까)
		candi.x = 20, candi.time = -1;//둘다 범위 바깥. 이거 그대로이면 잡아먹을거없는거겠지.
		
		//bfs 탐색
		while(!q.empty()){
			SHARK cur = q.front(); q.pop();
			//이미 더 거리짧은거(bfs이니까 거리순 탐색)있으면 더 찾을필요 없고, update
			if(candi.time != -1 and candi.time < cur.time) break; // 기존꺼보다 더 먼거리에 있으면 break. 걍 후보군 잡아먹지

			if(board[cur.x][cur.y] < shark_size and board[cur.x][cur.y]!=0){ //샤크보다 작은데 빈공간 아니면 
				//잡아먹기 가능!
				is_update = true;
				if(candi.x> cur.x or (candi.x == cur.x and candi.y> cur.y)){
					// 현재 잡아먹을 애가 더 위쪽, 그리고 더 왼쪽에 있으면
					// 잡아먹을 후보자를 cur로 업데이트 
					candi = cur;
				}
			}

			//4방향 진행 탐색
			for(int dir=0; dir<4; dir++){
				SHARK next;
				next.x = cur.x + dx[dir];
				next.y = cur.y + dy[dir];
				next.time = cur.time +1;
	
				//OOB
				if( next.x <0 or  next.x >=N or next.y<0 or next.y >=N ) continue;
				
				//방문하지 않았고, 상어보다 작거나 같은 곳이어야 일단 이동할수있음
				if(visited[next.x][next.y]== false and shark_size>=board[next.x][next.y]){
					visited[next.x][next.y]=true;
					q.push(next);
				} 
			}

		}

		if(is_update){
			shark= candi;
			++shark_eat;
			if(shark_eat==shark_size){
				++shark_size;
				shark_eat=0;
			}
			board[shark.x][shark.y]=0;

		}
	}
	cout << shark.time<<'\n';

	return 0;
}



 