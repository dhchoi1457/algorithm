//SWEA 1953. 탈주범 검거 


//상하좌우로 이동이 가능한지만 체크할수있으면,
//단순 bfs

#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second



const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
	// up 0
	// right 1
	// down 2
	// left 3


struct info
{
	int side[4];
	// up 0
	// right 1
	// down 2
	// left 3
	// 이러면 +2 %4하면 반대방향된다. 갸이득 
};

int board[52][52];
int dist[52][52];

int ans;

int N,M;//맵 세로 가로
int R,C;//맨홀뚜껑: 탈주범 시작 위치
int L; //경과시간


info pmap [52][52];

int main()
{
	int testnum;
	cin >> testnum;

	for(int k=1; k<=testnum; k++)
	{	


		cin >> N >> M >> R >> C >> L;

		//dist 초기화
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				dist[y][x]=-1;
			}
		}

		//board입력 
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				cin >> board[y][x];

				switch(board[y][x]){
					//파이프 X
					case 0:
						pmap[y][x].side[0]=0;
						pmap[y][x].side[1]=0;
						pmap[y][x].side[2]=0;
						pmap[y][x].side[3]=0;
						break;
					case 1:
						pmap[y][x].side[0]=1;
						pmap[y][x].side[1]=1;
						pmap[y][x].side[2]=1;
						pmap[y][x].side[3]=1;
						break;
					case 2:
						pmap[y][x].side[0]=1;
						pmap[y][x].side[1]=0;
						pmap[y][x].side[2]=1;
						pmap[y][x].side[3]=0;
						break;
					case 3:
						pmap[y][x].side[0]=0;
						pmap[y][x].side[1]=1;
						pmap[y][x].side[2]=0;
						pmap[y][x].side[3]=1;
						break;
					case 4:
						pmap[y][x].side[0]=1; //상 
						pmap[y][x].side[1]=1; //우 
						pmap[y][x].side[2]=0; //하
						pmap[y][x].side[3]=0; //좌 
						break;						
					case 5:
						pmap[y][x].side[0]=0;
						pmap[y][x].side[1]=1;
						pmap[y][x].side[2]=1;
						pmap[y][x].side[3]=0;
						break;
					case 6:
						pmap[y][x].side[0]=0; //상 
						pmap[y][x].side[1]=0; //우 
						pmap[y][x].side[2]=1; //하
						pmap[y][x].side[3]=1; //좌 
						break;						
					case 7:
						pmap[y][x].side[0]=1;
						pmap[y][x].side[1]=0;
						pmap[y][x].side[2]=0;
						pmap[y][x].side[3]=1;
						break;						
				}
			}
		}

		//start bfs
		queue <pair<int,int> > q;
		q.push({R,C});
		dist[R][C]=0;


		while(!q.empty()){
			auto cur = q.front(); q.pop();
			//cout << "now: " << cur.Y << ',' << cur.X <<'\n';
			if(dist[cur.Y][cur.X]>L) break;

			for(int dir=0; dir<4; dir++){
				int ny = cur.Y + dy[dir];
				int nx = cur.X + dx[dir];
				if(nx <0 or nx >=M or ny <0 or ny >= N) continue;
				if(dist[ny][nx]>=0) continue;
				if(pmap[cur.Y][cur.X].side[dir]==1 and pmap[ny][nx].side[ (dir+2)%4 ]==1 ){
					//cout << "nxt: " << ny << ',' << nx <<'\n';
					q.push({ny,nx});
					dist[ny][nx]= dist[cur.Y][cur.X]+1;
				}
			}
		}

		int ans =0;

		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				if(dist[y][x]<0) continue;
				if(dist[y][x]<L){ans++;}
			}
		}
		cout <<"#"<<k<<" "<< ans << '\n';
	}
	return 0;
}