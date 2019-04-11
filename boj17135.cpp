// boj 17135 캐슬디펜스
// 삼성 A형기출

#include <bits/stdc++.h>
using namespace std;

int board[17][17]= {0,};
int board2[17][17]={0,};
int board3[17][17]={0,};

int dist[17][17]= {0,};

int visited[17]= {0,}; // 궁수 위치 배열

int N,M,D;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int ret;

struct POSI{
	int y, x;
};


void update(){
	
	for(int y=0; y<M; y++){
		for(int x=0; x<N; x++){
			board2[y][x]=0;
		}
	}

	for(int y=0; y<M-1; y++){
		for(int x=0; x<N; x++){
			board2[y+1][x]= board3[y][x]; //한칸씩 아래로 전진
		}
	}

}

void simul(){
	// map가지고 각 궁수의 위치에서 bfs
	// 공격할놈 마킹하고,
	// 맵업데이트할때 공격한놈들 지운다

	int remove=0;

	for(int y=0; y<M; y++){
		for(int x=0; x<N; x++){
			board2[y][x] = board[y][x];
			board3[y][x] = board[y][x];
		}
	}
	
	int iter = M; // 맵 세로길이만큼 반복하면 적은 어차피 없어짐
	
	while(iter){
		iter--;

		for(int y=0; y<M; y++){
			for(int x=0; x<N; x++){
				board3[y][x]= board2[y][x];
			}
		}

		//각 궁수 위치에서 bfs
		for(int x=0; x<N; x++){

			for(int y=0; y<M; y++){
				for(int x=0; x<N; x++){
					dist[y][x]=-1;
				}
			}

			board2[M][x]= visited[x];
			if(board2[M][x]==0) continue;
			//cout << "x:" << x <<'\n';

			queue<POSI> q;
			POSI gs;
			gs.y = M;
			gs.x = x;
			
			q.push(gs);
			
			dist[M][x]=0;
			
			POSI candi;
			candi.y = -1;
			candi.x = 17;
			int candi_dist = 1e7;
			while(!q.empty()){
				POSI cur = q.front(); q.pop();

				//candi 갱신		
				if(dist[cur.y][cur.x]>D) break;
				if(board2[cur.y][cur.x]==1 and dist[cur.y][cur.x]>=1 and dist[cur.y][cur.x]<=D){
					//cout<< "check cur / dist / D: "<< cur.y <<','<< cur.x << '/'<< dist[cur.y][cur.x] << "/" << D <<'\n'; 
					if(dist[cur.y][cur.x] < candi_dist){
						candi_dist = dist[cur.y][cur.x];
						candi.y= cur.y;
						candi.x= cur.x;
					}else if(dist[cur.y][cur.x] == candi_dist and cur.x < candi.x){
						candi.y = cur.y;
						candi.x = cur.x;
					}
				}

				//다음단계 탐색
				for(int dir=0; dir<4; dir++){
					int ny = cur.y + dy[dir];
					int nx = cur.x + dx[dir];

					if(ny<0 or ny >=M or nx<0 or nx>=N) continue;
					if(dist[ny][nx]>=0) continue;
				 	POSI nxt;
				 	nxt.y = ny;
				 	nxt.x = nx;
				 	dist[nxt.y][nxt.x] = dist[cur.y][cur.x]+1;
				 	q.push(nxt);
				}
			}

			if(candi.y!=-1){
				board3[candi.y][candi.x]=2;
				//cout << "candi:" << candi.y << ','<< candi.x <<'\n';
			}

			// for(int y=0; y<M; y++){
			// 	for(int x=0; x<N; x++){
			// 		cout << board3[y][x] << ' ';
			// 	}
			// cout <<"\n";
			// }
		}

		//마킹한 2들 지움, 해치운적수 증가
		for(int y=0; y<M; y++){
			for(int x=0; x<N; x++){
				//cout << board3[y][x] << ' ';
				if(board3[y][x]==2){ board3[y][x]=0; remove++; }
			}
			//cout <<"\n";
		}
		//cout <<'\n';
		//map update
		update();
	}
	//cout <<"remove:"<< remove <<'\n';
	//cout <<"ret:"<< ret <<'\n';
	if(remove >= ret){
		ret = remove;
		//cout <<"update ret:"<< ret <<'\n';
	} 


}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//짜다가 M,N 바꿔서 풀어서ㅠ 그냥 입력을 바꿔서함
	cin >> M >> N >> D; 

	//cout << "D:" << D <<'\n';
	for(int y=0; y<M; y++){
		for(int x=0; x<N; x++){
			cin >> board[y][x];
		}
	}

	//궁수자리 3개 선택
	for(int x=0; x<N; x++){
		visited[x]=0;
	}

	ret = -1e7;
	for(int i=0; i<N-2; i++){
		visited[i]=1;
		for(int j=i+1; j<N-1; j++){
			visited[j]=1;
			for(int k=j+1; k<N; k++){
				visited[k]=1;

				simul();

				visited[k]=0;
			}
			visited[j]=0;
		}
		visited[i]=0;
	}

	cout << ret << '\n';
}