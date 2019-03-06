// boj 1600
// 말이 되고픈 원숭이

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int K,W,H;

int board[202][202];
int dist[202][202];

//3-dim movement
int dx[12]={1,0,-1,0,2,2,-2,-2,1,1,-1,-1};
int dy[12]={0,1,0,-1,1,-1,1,-1,2,-1,2,-2};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;

	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			cin >> board[i][j];
		}
		fill(dist[i],dist[i]+H,-1);
	}

	int tw = W-1; //target
	int th = H-1; 
	queue<pair<int,int>> Q;
	Q.push({0,0}); // start point
	dist[0][0]=0;

	while(!Q.emtpy()){
		auto cur = Q.front(); Q.pop();

		if(cur.X == tw and cur.Y== th){
			cout << 
			return 0;
		}

		//K번 말처럼 이동이 가능한 것에 대한 체크..
		//how?

		for(int dir=0; dir<12; dir++){
			if(K<=1 and dir>4){continue;}

			int nx = cur.X + dx[dir];
			int ny = cur.X + dy[dir];

			if(nx < 0 or nx >= W or ny < 0 or ny >=H) continue;
			if(dist[nx][ny]=)
		}

	}

	cout << "-1" <<'\n';

	return 0;
} 