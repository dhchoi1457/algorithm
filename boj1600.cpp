// boj 1600
// 말이 되고픈 원숭이

// 참고 : https://sungwoo91.tistory.com/16
// 벽부수고 이동하기에서와 유사한 방식
// 벽부수고 이동하기에서는 폭파를 사용했는지 안했는지를 고려하기 위해
// 비슷하게 풀었었음.

// 이런 경우, 한 지점에 도달하는 방식이 여러개이므로
// 그 지점에서의 거리가 갱신되는게 좀 불안? 이게 최저값이 맞나 그런 생각이 들었는데
// BFS의 특징을 생각해보면 최단거리임.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int K,W,H;

typedef struct{
	int r;
	int c;
	int knight;
}Monkey; 

int board[222][222];
int dist[222][222];
int visit[222][222][32]; // 마지막 차원에는 나이트로 k번 이동 가능함을 표시 

//3-dim movement
int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

int ndr[8]={2,2,-2,-2,1,1,-1,-1};
int ndc[8]={1,-1,1,-1,2,-2,2,-2};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;

	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			cin >> board[i][j];
		}
		//fill(dist[i],dist[i]+H,-1);
	}

	int tr = W-1; //target
	int tc = H-1; 
	queue<Monkey> Q;
	Monkey start = {0,0,K};
	Q.push(start); // start point
	dist[0][0]=0;
	visit[0][0][K]=1;

	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();

		int cr = cur.r;
		int cc = cur.c;
		int ck = cur.knight;

		//cout << "cur:" << cr << ' ' << cc <<' '<< ck <<'\n'; 
		//cout << "dist: "<< dist[cr][cc] <<'\n';
		if(cr == tr and cc== tc){
			cout << dist[cr][cc] << '\n';
			return 0;
		}

		//K번 말처럼 이동이 가능한 것에 대한 체크..
		//how?

		for(int dir=0; dir<4; dir++){
			int nr = cr + dr[dir];
			int nc = cc + dc[dir];
			if(nr < 0 or nr >= W or nc < 0 or nc >=H) continue;
			if(visit[nr][nc][ck]==1 or board[nr][nc]==1) continue;
			Q.push({nr,nc,ck});
			visit[nr][nc][ck]=1;
			dist[nr][nc] = dist[cr][cc]+1;		
		}

		if(ck>0){ // 말처럼 움직일수 있으면 이런 경우도 가능

			for(int dir=0; dir<8; dir++){
				int nr = cr + ndr[dir];
				int nc = cc + ndc[dir];

				if(nr < 0 or nr >= W or nc < 0 or nc >=H) continue;
				if(visit[nr][nc][ck-1]==1 or board[nr][nc]==1) continue;
				Q.push({nr,nc,ck-1});
				visit[nr][nc][ck-1]=1;
				dist[nr][nc] = dist[cr][cc]+1;		
			}
		}

	}

	cout << "-1" <<'\n';

	return 0;
} 