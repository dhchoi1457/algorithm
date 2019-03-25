// boj 16234
// 인구이동
// 2018 하반기 삼성전자 ds SW역량기출

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};

int board[52][52];
int area_update[2501];

int N,L,R;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >>N; // map size
	cin >>L >> R; // 값 차이가 L이상 R이하일때 국경 개방(인구이동 발생)

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			//cout << board[i][j] << ' ';
		}
		//cout << '\n';
	}

	int area_index = 0;
	int move_count =0;
	bool is_update = true;

	while(is_update){
		//cout << "move_count:" << move_count <<'\n';
		is_update=false;

		int visited[52][52]={0,};
		int area[52][52]={0,};

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(visited[i][j]==1) continue;

				queue <pair<int,int> > Q;
	 			Q.push({i,j});
				visited[i][j]=1;

				area_index++;
				area[i][j]=area_index; // 연합 영역 표시
				int sum = board[i][j];
				int count =1;

				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();

					for(int dir=0; dir<4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
							
						int gap = abs(board[cur.X][cur.Y]-board[nx][ny]);
						
						if(nx<0 or nx>=N or ny<0 or ny>= N) continue;
						if(visited[nx][ny]==1) continue;
						if(gap>=L and gap<=R){
							Q.push({nx,ny});
							visited[nx][ny]=1;
							sum+=board[nx][ny];
							count++;
							area[nx][ny]=area_index;
							is_update = true;
						}
					}
				}
				area_update[area_index]= sum/count;

				//이걸 업데이트 한꺼번에 해야 복잡도 줄어든다 
				// for(int i=0; i<N; i++){
				// 	for(int j=0; j<N; j++){
				// 		if(area[i][j] != area_index) continue;
				// 		board[i][j]=sum/count;
				// 	}
				// }
			}
		}		
		if(is_update){
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					int tmp= area[i][j];
					board[i][j] = area_update[tmp];
				}
			}
			move_count++;
		} 
		else{break;}
	}
	cout << move_count;
	return 0;
}



 