// boj 6593
// 상범빌딩

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int L,R,C;

string board[32][32]; // L R C 
int dist[32][32][32];
//3-dim movement
int dl[6]={1,0,0,-1,0,0};
int dr[6]={0,1,0,0,-1,0};
int dc[6]={0,0,1,0,0,-1};

int sl, sr, sc; // start
int el, er, ec; // end

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> R >> C; 

	// L : 상범빌딩 층수
	// R : 한 층의 row
	// C : 한 층의 column
	while(L!=0 and R!=0 and C!=0){
		int isTrap = 1;

		for(int i=0; i<L; i++){
			for(int j=0; j<R; j++){
				cin >> board[i][j];
				
				for(int k=0; k<C; k++){
					if(board[i][j][k]=='S'){sl=i; sr=j; sc=k;}
					if(board[i][j][k]=='E'){el=i; er=j; ec=k;}
				}
				fill(dist[i][j],dist[i][j]+C,-1);
			}	
		}
		
		queue<pair<int,pair<int,int>>> Q;
		Q.push({sl,{sr,sc}});
		dist[sl][sr][sc]=0;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();

			//cout << "cur : " << cur.X << ' ' << cur.Y.X << ' ' << cur.Y.Y <<'\n';

			if(cur.X == el and cur.Y.X == er and cur.Y.Y == ec ){
				
				cout << "Escaped in "<< dist[el][er][ec] << " minute(s)." <<'\n';
				isTrap = 0;
				break;
			}

			for(int dir=0; dir<6; dir++){
				int nl = cur.X + dl[dir];
				int nr = cur.Y.X + dr[dir];
				int nc = cur.Y.Y + dc[dir];

				if(nl <0 or nl >= L or nr <0 or nr >= R or nc <0 or nc >=C) continue;
				if(dist[nl][nr][nc]>=0 or board[nl][nr][nc]=='#') continue;
				Q.push({nl,{nr,nc}});
				dist[nl][nr][nc]= dist[cur.X][cur.Y.X][cur.Y.Y]+1;
			}
		}

		if(isTrap==1){
			cout << "Trapped!" << '\n';
		}

		cin >> L >> R >> C; 
	}

	return 0;
} 