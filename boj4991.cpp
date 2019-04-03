// boj4991
// 로봇청소기 

// x,y 헷갈리는거 조심

//일단 탐욕적 방법으로했는데,
//이렇게하면 안되나보네..
// 그래도 이거 잘 구현했다.


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

string board[102];
int dist[102][102];


// r = w
// h = c
int r,c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){

		int sy, sx;
		cin >> r >> c;

		if(r==0 and c==0){break;}

		for(int i=0; i<c; i++){
			cin >> board[i];
			
			for(int j=0; j<r; j++){
				if(board[i][j]=='o'){
					sy=i;
					sx=j;
				}
			}

		}

		//dist 초기화
		for(int y=0; y<c; y++){
			for(int x=0; x<r; x++){
				dist[y][x]=-1;
			}
		}



		//cout <<"start y,x:" <<sy <<','<< sx << '\n'; 

		queue<pair<int,int> > Q;


		Q.push({sx,sy});
		dist[sy][sx]=0;

		//bfs시작
		int ret=0;

		while(!Q.empty()){
				
			auto cur = Q.front(); Q.pop();
			//cout << '\n';
			//cout << "cur :" << cur.Y <<',' << cur.X << ',' << board[cur.Y][cur.X] << '\n'; 
			if(board[cur.Y][cur.X]=='*'){
				//cout << "find)))))))))))))))))))))))))))))))))" << '\n';
				ret+=dist[cur.Y][cur.X];
				
				board[cur.Y][cur.X]='.';

				//dist 초기화. 갔던길 다시 갈수 있어야지
				for(int y=0; y<c; y++){
					for(int x=0; x<r; x++){
						dist[y][x]=-1;
					}
				}
				dist[cur.Y][cur.X]=0;

				//Q비우기
				while(!Q.empty()){
					Q.pop();
				}
			}

			for(int dir=0; dir<4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx<0 or nx>=r or ny<0 or ny>=c) continue;
				if(board[ny][nx]=='x' or dist[ny][nx]>=0) continue;

				Q.push({nx,ny});
				dist[ny][nx]=dist[cur.Y][cur.X]+1;
				//cout << "nxt :" << ny <<',' << nx << ',' << dist[ny][nx] << '\n' ; 
			}
		}
		
		if(ret==0){cout << "-1" <<'\n';}
		else{cout << ret << '\n';}
	}	
	return 0;
}



 