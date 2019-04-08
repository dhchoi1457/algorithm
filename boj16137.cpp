// boj 16137
// 견우와직녀
// 거진 풀었는데, 어디서 틀리는건지 모르겠다.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[12][12];
int dist[12][12][2]; // 3차원에서 0일떈 오작교 안만들고, 1일땐 만들고.

struct POSI{
	int y,x;
	bool new_bridge;
	bool before_bridge;
};


void cross(){
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			int check =0;
			if(board[y][x]==1) continue;
			if(x-1>=0 and y-1>=0 and board[y][x-1]==0 and board[y-1][x]==0) check=1;
		 	if(x-1>=0 and y+1>=0 and board[y][x-1]==0 and board[y+1][x]==0) check=1;
		 	if(x+1>=0 and y-1>=0 and board[y][x+1]==0 and board[y-1][x]==0) check=1;
		 	if(x+1>=0 and y+1>=0 and board[y][x+1]==0 and board[y+1][x]==0) check=1;
			if(check==1){
				board[y][x]=-1;
			}	
		}
	}
	
}

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};


int dist_update(int nt, int m){
	if(nt/m>=1 and nt%m==0){
		return nt;
	}
	else{
		int tmp = (nt/m +1)*m;
		return tmp;
	}
}

void bfs(){
	
	queue<POSI> q;

	POSI st;
	st.y =0;
	st.x =0;
	st.new_bridge=false;
	st.before_bridge=false;

	q.push(st);
	dist[st.y][st.x][0]=0;

	while(!q.empty()){
		POSI cur = q.front(); q.pop();
		//cout << "**cur :" << cur.y << ',' << cur.x << " new:" << cur.new_bridge << " before:"<< cur.before_bridge<<'\n';
		for(int dir=0; dir<4; dir++){
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if(ny<0 or ny >=N or nx<0 or nx>=N) continue;
			if(board[ny][nx]==-1) continue;
			
			//board의 케이스를 나누어접근 
			//1일때 - 그냥 지나간다  
			if(board[ny][nx]==1){
				//dist는 처음에 큰 수로 초기화되어있음.
				//그에 맞추어 현재 나보다 큰 경우에만 갱신
				//나보다 작은 경우는 이미 지나갔던 경우이므로
				//갱신하지 않음
				//cout << "nxt1 :" << ny << ',' << nx <<'\n';
				//cout << "check1 dist nxt:"<< dist[ny][nx][cur.new_bridge] <<" dist_now:"<< dist[cur.y][cur.x][cur.new_bridge]+1 << '\n';
				if( dist[ny][nx][cur.new_bridge] > dist[cur.y][cur.x][cur.new_bridge]+1 ){
					dist[ny][nx][cur.new_bridge] = dist[cur.y][cur.x][cur.new_bridge]+1;
					POSI nxt;
					nxt.y = ny; nxt.x = nx; nxt.before_bridge = false; nxt.new_bridge=cur.new_bridge;
					//cout << "push :" << ny << ',' << nx <<'\n';
					q.push(nxt);
				}
			}
			//0일때 - 상황봐서 오작교를 놔야함
			else if(board[ny][nx]==0){
				if(cur.before_bridge==false and cur.new_bridge==false){
					board[ny][nx]=M; // 주기 M인것으로 맵 변함
					//dist 업데이트는 어떻게?
					//cout << "nxt0 :" << ny << ',' << nx <<'\n';
					int tmp_dist = dist_update(dist[cur.y][cur.x][cur.new_bridge]+1,M);
					//cout << "update :" << dist[cur.y][cur.x][cur.new_bridge]+1 <<','<< M <<'\n';
					//cout << "check0 dist nxt:"<< dist[ny][nx][1] <<" tmp:" << tmp_dist <<'\n';
					if(dist[ny][nx][1] > tmp_dist){
						dist[ny][nx][1] = tmp_dist;
						POSI nxt;
						nxt.y = ny; nxt.x = nx; nxt.before_bridge = true; nxt.new_bridge=true;
						q.push(nxt);
						//cout << "push :" << ny << ',' << nx <<'\n';
					}
				}
			}
			//오작교가 있을떄, 주기에 맞추어 건너가야함
			else if(board[ny][nx]>=2){
				if(cur.before_bridge==false){
					int tmp_dist = dist_update(dist[cur.y][cur.x][cur.new_bridge]+1,board[ny][nx]);
					if(dist[ny][nx][cur.new_bridge] > tmp_dist){
						dist[ny][nx][cur.new_bridge] = tmp_dist;
						POSI nxt;
						nxt.y = ny; nxt.x = nx; nxt.before_bridge = true; nxt.new_bridge=cur.new_bridge;
						q.push(nxt);
						//cout << "push :" << ny << ',' << nx <<'\n';
					}		
				}
			}


		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cin >> board[y][x];
			dist[y][x][0]= 1e7;
			dist[y][x][1]= 1e7;

			//cout << board[y][x] << ' ';
		}
		//cout <<'\n';
	}

	cross(); //교차지점 -1로 체크. -1에는 오작교 개설 불가 


	bfs();

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cout << min(dist[y][x][0],dist[y][x][1]) << ' ';
		}
		cout <<'\n';
	}

	cout << min(dist[N-1][N-1][0],dist[N-1][N-1][1]) << '\n';

	//cout << "test:"<<dist_update(2,6) <<'\n';
	//cout << dist[N-1][N-1] <<'\n';
	return 0;
}

 